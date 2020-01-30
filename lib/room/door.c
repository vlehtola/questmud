
mapping dir, file, code, link_room, desc, door_label;
mapping open, locked, door_id;

door_reset() {
  dir = ([ ]);
  file = ([ ]);
  code = ([ ]);
  link_room = ([ ]);
  desc = ([ ]);
  door_label = ([ ]);
  open = ([ ]);
  locked = ([ ]);
  door_id = ([ ]);
}

convert_id(id) {
  int i;
  while(i<10) {
     if (door_id[i] = id) { return i; }
     i += 1;
  }
}

set_locked(arg,num) {
  if (!code[num] && link_room[num] && link_room[num]->query_door_code(num)) {
    code[num] = call_other(link_room[num], "query_door_code",num);
  }
  locked[num] = arg;
}

query_door_locked(num) { return locked[num]; }

set_open(arg,num) { open[num] = arg; }

query_door_open(num) { return open[num]; }

random_door_code(quality, num) {
    string str;
    int i;
    str = "";
    while(i < quality) {
      str = str + random(10);
      i += 1;
    }
    code[num] = str;
    if (link_room[num]) { call_other(link_room[num], "set_door_code",code[num],num); }
}

set_door_code(str, num) { 
  code[num] = str;
  if (link_room[num] && !link_room[num]->query_door_code(num)) {
    call_other(link_room[num], "set_door_code",code[num],num);
  }
}

query_door_code(num) { return code[num]; }

set_door_link(str, num) {
  link_room[num] = str;
  call_other(str, "load");
}

set_door_desc(str,num) { desc[num] = str; }

set_door_label(str,num) { door_label[num] = str; }

door_label(num) {
  if (door_label[num]) { return "'"+door_label[num]+"' "; }
  return "";
}

query_door_desc(num) {
  if (desc[num]) { return desc[num]; }
  return "";
}

write_door_shorts() {
  string str;
  int i;
  str = m_indices(dir);
  while(i < sizeof(str)) {
    if (query_door_open(str[i])) {
       write("An open "+query_door_desc(str[i])+
          door_label(str[i])+"is leading to the "+query_door_dir(str[i])+".\n");
    } 
    else {
      if (query_door_locked(str[i])) {
	write("A locked "+query_door_desc(str[i])+
	      door_label(str[i])+"is leading to the "+query_door_dir(str[i])+".\n");
      }
      else {
	write("A closed "+query_door_desc(str[i])+
	      door_label(str[i])+"is leading to the "+query_door_dir(str[i])+".\n");
      }
    }
    i += 1;
  }
}

door_long_desc(str) {
  int num;
  if (!sscanf(str, "door %d",num)) {
     if (str != "door") { return 0; }
  }
  num = get_id(num);
  if (!num) { write("What?\n"); return 1; }  //write("No such a door.\n"); return 1; }

  write_long_desc(num);
  return 1;
}


write_long_desc(num) {
  write("This");
  if (desc[num]) write(" "+desc[num]);
  write(" door ");
  if (door_label[num]) { write("labelled '"+door_label[num]+"' "); }
  if (locked[num]) { write("is locked.\n"); }
  else if (open[num]) { write("is open.\n"); }
  else { write("is closed.\n"); }
  write("It leads to the "+dir[num]+".\n\n");
  write("Available door commands:\n");
  write("  open door [number]\n");
  write("  close door [number]\n");
  write("  lock door [number] with key\n");
  write("  unlock door [number] with key\n");
}


door_init() {
  add_action("open", "open");
  add_action("close", "close");
  add_action("lock", "lock");
  add_action("unlock", "unlock");
}

set_door_dir(str, path, num) {
  dir[num] = str;  
  file[num] = path;
}

query_door_dir(num) { return dir[num]; }

query_door_file(num) { return file[num]; }

get_id(int num) {
  string str;
  int i;
  if (!num) { num = 1; }
  str = m_indices(dir);
  if (num > sizeof(str)) { return; }
  return str[(num-1)];
}

open(string str) {
  int num;
  if (!str) return;
  if (!sscanf(str, "door %d",num)) {
     if (str != "door") { return 0; }
  }
  num = get_id(num);
  if (!num) { write("No such a door.\n"); return 1; }

  if (open[num]) { write("The door is already open.\n"); return 1; }
  if (locked[num]) { write("The door is locked.\n"); return 1; }
  write("You open the door.\n");
  open[num] = 1;
  if (link_room[num]) call_other(link_room[num], "door_opened",num);
  add_exit(dir[num], file[num]);
  return 1;
}

door_opened(num) {
  tell_room(this_object(), "The door opens.\n");
  if (!file[num]) { write("Door id not matching.\n"); return; } 
  open[num] = 1;
  add_exit(dir[num],file[num]);
  return 1;
}

close(str) {
  int num;
  if (!str) return;
  if (!sscanf(str, "door %d",num)) {
     if (str != "door") { return 0; }
  }
  if (!num) { num = 1; }
  num = get_id(num);
  if (!open[num]) { write("The door is already closed.\n"); return 1; }
  write("You close the door.\n");
  open[num] = 0;
  remove_exit(dir[num]);
  if (link_room[num]) call_other(link_room[num], "door_closed", num);
  return 1;
}

door_closed(num) {
  tell_room(this_object(), "Someone closes the door.\n");
  open[num] = 0;
  remove_exit(dir[num]);
  return 1;
}

lock(string str) {
  string door, key, tmp;
  object ob;
  int num;
  if (!str || !sscanf(str, "door %s", tmp) && str != "door") return;
  if (sscanf(str,"%s with %s", door, key) != 2) {
    write("Lock door with what?\n");
    return 1;
  }
  if (!sscanf(door, "door %d",num)) {
    num = 0; /* Siis eka doori. */
  }
  num = get_id(num);
  if (!num) { write("No such a door.\n"); return 1; }

  ob = present(key, this_player());
  if (!ob) { write("You don't have a "+key+".\n"); return 1; }
  if (!ob->query_key_code()) { write("That is not a key.\n"); return 1; }

  // added num to ob->query_keycode(num), allowing masterkeys to work properly --as 12.1.02
  if (ob->query_key_code(num) != query_door_code(num)) {
        write("The key does not fit.\n");
        return 1;
  }
  if (open[num]) { write("The door must be closed first.\n"); return 1; }
  if (locked[num]) { write("The door is already locked.\n"); return 1; }
  write("You lock the door.\n");
  locked[num] = 1;
  if (link_room[num]) call_other(link_room[num], "door_locked", num);
  return 1;
}

door_locked(num) {
  tell_room(this_object(), "You hear someone locking the door.\n");
  locked[num] = 1;
  return 1;
}

unlock(string str) {
  string door, key, tmp;
  object ob;
  int num;
  if (!str || !sscanf(str, "door %s", tmp) && str != "door") return;
  if (sscanf(str,"%s with %s", door, key) != 2) {
    write("Unlock door with what?\n");
    return 1;
  }
  if (!sscanf(door, "door %d",num)) {
    num = 0; /* Siis eka doori. */
  }
  num = get_id(num);
  if (!num) { write("No such a door.\n"); return 1; }

  ob = present(key, this_player());
  if (!ob) { write("You don't have a "+key+".\n"); return 1; }
  if (!ob->query_key_code()) { write("That is not a key.\n"); return 1; }

  // added num to ob->query_keycode(num), allowing masterkeys to work properly --as 12.1.02
  if (ob->query_key_code(num) != query_door_code(num)) {
        write("The key does not fit.\n");
        return 1;
  }
  if (open[num]) { write("The door is already open.\n"); return 1; }
  if (!locked[num]) { write("The door not locked.\n"); return 1; }
  write("You unlock the door.\n");
  locked[num] = 0;
  if (link_room[num]) call_other(link_room[num], "door_unlocked", num);
  return 1;
}

door_unlocked(num) {
  tell_room(this_object(), "You hear someone unlocking the door.\n");
  locked[num] = 0;
  return 1;
}
