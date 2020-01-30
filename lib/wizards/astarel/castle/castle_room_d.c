#define SAVEDIR "/data/castle/castle_"
#define DEBUG

inherit "/room/room.c";

int saveable, id, someone_present, i, state, value;
int amount = 50;
string file;
object *temp;
string *list;
object *items;

/* protos */

generate_chests();

init() {
  ::init();
  add_action("begin_force_open", "force");
}

void reset(status arg) {
  if(arg) return;
  temp = ({});
}

void debug_write(string msg) {
#ifdef DEBUG
    tell_object(find_player("astarel"),msg);
#endif
  return;
}

create_chest_file() {
  string this_room, fname, dummy, chest_file;
  int number, count, i, j;
  count = 0;
  
  this_room = file_name(this_object());
  
  sscanf(this_room, "%s/castle_%d/room%d", fname, number, dummy);
  chest_file = fname+"/castle_"+number+"/chests";
  debug_write("chest_file: "+chest_file+"\n");

  while(file_size("/data/castle/castle_"+number+"/room"+count+".c") != -1) {
    count++;
  }

  debug_write("nro of rooms: "+count+"\n");
  rm(chest_file);
  debug_write("DEBUG: starting to refresh BLAA BLAA! chestfile @ room_d\n");

  for(i=0; i<count; i++) {
    debug_write("i: "+i+"\n");
    debug_write("/data/castle/castle_"+number+"/room"+i+"\n");
    debug_write(":: /data/castle/castle_"+number+"/room"+i+"\n");
    call_other("/data/castle/castle_"+number+"/room"+i, "???",0);

    items = all_inventory("data/castle/castle"+number+"/room"+i);
    for(j=0; j<sizeof(items); j++) {
      debug_write("entered sizeof(items) loop, j="+j+"\n");
if(items[j]->query_sealed()) write_file(chest_file, items[j]->query_id()+":"+items[j]->query_code()+":"+items[j]->query_label()+":/data/castle/castle_"+number+"/room"+i+"\n");  
    }
  }
}

create_guard_file() {
  string this_room, fname, dummy, guard_file;
  int number, count, i, j;
  count = 0;
  
  this_room = file_name(this_object());
  
  sscanf(this_room, "%s/castle_%d/room%d", fname, number, dummy);
  guard_file = fname+"/castle_"+number+"/guards";
  debug_write("guard_file: "+guard_file+"\n");

  while(file_size("/data/castle/castle_"+number+"/room"+count+".c") != -1) {
    count++;
  }
  
  debug_write("nro of rooms: "+count+"\n");
  rm(guard_file);

  debug_write("DEBUG: starting refresh guardfile @ room_d\n");

  for(i=0; i<count; i++) {
    debug_write("i: "+i+"\n");
    debug_write("/data/castle/castle_"+number+"/room"+i+"\n");
    debug_write("::"+"/data/castle/castle_"+number+"/room"+i+"\n");
    call_other("/data/castle/castle_"+number+"/room"+i, "???");
    items = all_inventory(find_object("/data/castle/castle_"+number+"/room"+i));
    for(j=0; j<sizeof(items); j++) {
      debug_write("entered sizeof(items) loop, j="+j+"\n");
      if(items[j]->is_guard()) write_file(guard_file, items[j]->query_id()+":"+items[j]->query_guard()+":"+items[j]->query_level()+":/data/castle/castle_"+number+"/room"+i+"\n");
    }
  }
}

begin_force_open(arg) {
  int num;
  object force_ob;

  if(!arg) return 1;

  if(this_player()->query_str() < 100) {
    write("You consider it for a moment, but quickly come into conclusion that this job requires someone with more muscle.\n");
    return 1;
  }

  if (!sscanf(arg, "door %d",num)) {
    if (arg != "door") {
      write("Usage: force <item>\n");
      return 1;
    }
  }

  if(num == 0) num = 1;

  write("doorcode\n");
  if(environment(this_player())->query_door_code(num) == 0) {
    write("No such door here.\n");
    return 1;
  }

  write("locked\n");
  if(environment(this_player())->query_door_locked(num) != 1) {
    write("The door isn't locked.\n");
    return 1;
  }

  write("dummy\n");
  if(present("forcedummy")) {
    write(present("forcedummy")->who()+" is allready working here.\n");
    return 1;
  }

  write("You start breaking the door. This could take a while...\n");
  say(capitalize(this_player()->query_name())+" starts pounding the door.\n");
  state = 1;
  force_ob = clone_object("/castle/obj/force_dummy");
  force_ob->set_who(this_player()->query_name());
  move_object(force_ob, environment(this_player()));
  call_out("do_forcing", 5, num);
  write_file("/data/castle/door_force_open", ctime()+": "+this_player()->query_name()+"("+this_player()->query_level()+") started to force open door in '"+file_name(environment(this_player()))+"'\n");

  return 1;
}

do_forcing(arg) {
  int what, delay;

  if(state == 0) {
    write("You have been distracted too much and abort your work.\n");
    destruct(present("forcedummy"));
    value = 0;
  }

  if(state == 1) {
    if(!present("forcedummy")) {
      state = 0;
      return 1;
      remove_call_out("do_forcing");
    }

    if(!present(lower_case(present("forcedummy")->who()))) {
      state = 0;
      destruct(present("forcedummy"));
      return 1;
    }

    else {
      delay = random(10)+(5000/this_player()->query_str());
      call_out("do_forcing", delay, arg);
    }
  }

  if(state == 2) {
    destruct(present("forcedummy"));
    environment(this_player())->set_locked(0, arg);
    write("You manage to force the door open.\n");
    
    write_file("/data/castle/door_force_open", ctime()+": "+this_player()->query_name()+"("+this_player()->query_level()+") finished force opening door in '"+file_name(environment(this_player()))+"'\
n");
  }

  what = random(100)+value;

  switch(what) {
  case 0..90:
    write("Your efforts have little effect, but you continue working anyway.\n");
    break;
  case 91..120:
    write("You chip away small bits of metal.\n");
    say("Small dents start to form on the door as "+capitalize(this_player()->query_name())+" continues to pound the door.\n");
    value++;
    break;
  case 121..140:
    write("There is a promising creaking coming from the door, after each successfull pound.\n");
    say("Door's hinges give away a nasty sound.\n");
    value += 3;
    break;
  case 141..180:
    write("Parts of the door start to teal off.\n");
    say(capitalize(this_player()->query_name())+" manages to break part of the door.\n");
    value += 7;
    break;
  default:
    write("You relax a bit, after this long hours of work. You hope it was worth it.\n");
    say(capitalize(this_player()->query_name())+" finally breaks the door open.\n");
    state = 2;
  }
}

query_owner() {
  string *owners, owner, ownee, owned;
  int i, code, iid;

  owners = read_file("/data/castle/owner_list");
  owner = explode(owners, "\n");

  for(i=0; i<sizeof(owner); i++) {
    sscanf(owner[i], "%s:%d", ownee, owned);
    iid = environment(this_player())->query_castle_id();
    if(owned == iid) {
	if(capitalize(this_player()->query_name()) == ownee) return ownee;
    }
  }
}

int enter_portal(string arg) {
  string trgt_room;
  
  switch(arg) {
  case "inn": trgt_room = "/world/city/inn";
    break;
  case "cs": trgt_room = "/world/city/cs";
    break;
  default: 
    return 0;
  }
  
  tell_room(trgt_room, "Portal opens temporarily as "+this_player()->query_name()+" enters.\n");
  tell_room(environment(this_player()), this_player()->query_name()+" steps through the portal, leaving for "+arg+".\n");
  tell_object(this_player(), "You step through the portal.\n");
  this_player()->move_object(trgt_room);
  return 1;
}

generate_chests() {
  int i, chest_id, chest_code, dummy, number;
  object ob;
  string *list2, file2, chest_label, chest_path, fname, filee;

  debug_write("DEBUG: generating chests to room @ room_d\n");

  sscanf(file_name(this_object()), "%s/castle_%d/room%d", fname, number, dummy);
  debug_write("fname: "+fname+", number: "+number+", dummy: "+dummy+"\n");

  filee = fname+"/castle_"+number+"/chests";
  debug_write("filee = "+filee+"\n");
  if(file_size(filee) == -1) {
    debug_write("filee not found, generating empty\n");
    write_file(filee, "\n");
    return;
  }
  file2 = read_file(filee);
  debug_write("file2= "+file2+"\n");
  list2 = explode(file2, "\n");

  debug_write("DEBUG: starting chest generation.\n");
  debug_write("sizeof(list2): "+sizeof(list2)+"\n");

  for(i=0; i<sizeof(list2); i++) {
    debug_write("list2["+i+"] = "+list2[i]+"\n");
    sscanf(list2[i], "%d:%d:%s:%s", chest_id, chest_code, chest_label, chest_path);
    debug_write("id: "+chest_id+", code: "+chest_code+", label: "+chest_label+", path: "+chest_path+"\n");
    if(find_object(chest_path) == this_object()) {
      debug_write("DEBUG: chest is in this room\n");
      ob = clone_object("/castle/obj/chest");
      ob->force_set_id(chest_id);
      ob->set_label(chest_label);
      ob->force_set_combo(chest_code);
      ob->set_path(give_me_path()+"/chest_"+chest_id);
      //ob->restore_chest();
      debug_write("moving chest to "+chest_path+"\n");
      move_object(ob, find_object(chest_path));
            
    }
  }
  return 1;
}

generate_guards() {
  int i, dummy, number, lvl, guard_id;
  object ob;
  string *list2, file2, fname, filee, guard_file, guard_path, guardi;

  debug_write("DEBUG: generating guards into room @ room_d\n");
  
  sscanf(file_name(this_object()), "%s/castle_%d/room%d", fname, number, dummy);

  filee = fname+"/castle_"+number+"/guards";
  if(file_size(filee) == -1) {
    debug_write("filee not found, generating empty\n");
    write_file(filee, "\n");
  }
  file2 = read_file(filee);
  list2 = explode(file2, "\n");

  for(i=0; i<sizeof(list2); i++) {
    sscanf(list2[i], "%d:%s:%d:%s", guard_id, guard_file, lvl, guard_path);
    if(find_object(guard_path) == this_object()) {
      ob = clone_object(guard_file);
      ob->set_level(lvl);
      ob->set_exp(1);
      ob->force_set_id(guard_id);
      ob->restore("/data/castle/castle_"+number+"/guard_"+guard_id);
      move_object(ob, find_object(guard_path));
    }
  }
  return 1;
}

// returns path to this castle
give_me_path() {
  string path, tpath, fname;
  int dummy, number;
  
  sscanf(file_name(this_object()), "%s/castle_%d/room%d", fname, number, dummy);
  debug_write("givemepath :: fname: "+fname+", number: "+number+", dummy: "+dummy+"\n");
  path = fname+"/castle_"+number;
  debug_write("path = "+path+"\n");
  return path;
}

void room_heal(int amount) {
  object *occupants;
  occupants = all_inventory(this_object());

  for(i=0; i<sizeof(occupants); i++) {
    if(living(occupants[i])) {
      occupants[i]->add_hp(amount);
      occupants[i]->add_sp(amount);
      someone_present = 1;
    }
  }
  if(someone_present) { 
    call_out("room_heal", 15, amount);
    tell_room(this_object(), "A small pulse of warmth passes over this room.\n");
  }
  else {
    someone_present = 0;
    tell_room(this_object(), "Lights in this room dim slightly, as the runes fade out.\n");
  }
}

int is_saveable() {
  return saveable;
}

void set_saveable(int arg) {
  saveable = arg;
}

int add_chest(int iidee, int code, string label) {
  int number, dummy, chest_id, chest_code, between, free_id;
  string fname, this_room, chest_file, chest_label;
  string tfile, *tlist, chest_location;
  this_room = file_name(this_object());

  sscanf(this_room, "%s/castle_%d/room%d", fname, number, dummy);

  chest_file = fname+"/castle_"+number+"/chests";

  tfile = read_file(chest_file);
  tlist = explode(tfile, "\n");
  
  debug_write("id: "+iidee+"\n");
  if(iidee == 0) {
    for(i=0; i<sizeof(tlist); i++) {
      debug_write("DEBUG: tlist["+i+"] = "+tlist[i]+"\n");
      sscanf(tlist[i], "%d:%d:%s:%s", chest_id, chest_code, chest_label, chest_location);
      debug_write("DEBUG@add_chest(): chest_id: "+chest_id+", i: "+i+"\n");
      free_id = chest_id+1;
      if(chest_id != i) {
	debug_write("chest_id != i\n");
	between = i;
      }
    }
    iidee = free_id;
    if(between > 0) iidee = between;
  }
  
  debug_write("DEBUG: writing chest_file, ID: "+iidee+", code: "+code+", label: "+label+", location: "+this_room+"\n");
  
  debug_write("this_room: "+this_room+"\n");
  debug_write("chest_file = "+chest_file+"\n");
  //write_file(chest_file, iidee+":"+code+":"+label+":"+this_room+"\n");
  return iidee;
}


 
int save_room() {
  int k, room;
  string str, tmp1, tmp2;
  list = allocate(100);
  k = 0;
  file = file_name(this_object());

  debug_write("DEBUG: file@start = "+file+"\n");
  sscanf(file, SAVEDIR+"%d/room%d", id, room);
  temp = all_inventory(this_object());
  debug_write("size: "+sizeof(temp)+"\n");
  for(i=0; i<sizeof(temp); i++) {
    if(temp[i]->is_castleitem()) {
      str = file_name(temp[i]);
      if(str) {
	sscanf(str,"%s#%d",tmp1,tmp2);
	debug_write("tmp1: "+tmp1+"\n");
	list[k] = tmp1;
	k++;
      }
      debug_write("DEGUB: saving "+tmp1+"\n");
    }
  }
  debug_write("DEBUG: file@save = "+file+"\n");
  if(file) save_object(file);
  else { 
    write("FATAL ERROR! No file.\n");
    return 0;
  }
  debug_write("Room saved.\n");
  return 1;
}

int restore_room() {
  int i, j, match, *cloned;
  mixed *listi;
  string templist, *listlines;
  object ob;
  match = 0;
  file = file_name(this_object());

  if(file) restore_object(file);
  else {
    return 1;
  }
  temp = all_inventory(this_object());
  for(i = 0; i<sizeof(list); i++) {
    if(list[i] != 0) {
      debug_write("DEBUG@restore_room: list["+i+"] = "+list[i]+"\n");
/*
      if(list[i] == "/castle/obj/chest") {
	debug_write("on chesti\n");
	if(file_size(chest_file) != -1) {
	  templist = read_file(chest_file);
	  listlines = explode(templist, "\n");
	  for(j=0; j<sizeof(listi); j++) {
	    listi = explode(listlines[j], ":");
	    debug_write(file_name(environment(this_object()))+"\n");
	  write(listi[2]+"\n");
	  //	  if(listi[2] == 
	  }
	}
      }
*/
      move_object(clone_object(list[i]), this_object());
    }
  }
  return 1;
}

void set_amount(int arg) {
  amount = arg;
}
