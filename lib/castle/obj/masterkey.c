string keys_file = (string)"/data/castle/keys/key_";

short() {  
  return "A small golden key";
}
  
long() {
  write("A small golden key.\n");
}

get() {
  return 1;
}

drop() {
  //  return 1;
}

id(str) {
  if(str == "key" || str == "masterkey") return 1;
}

query_key_code(doornum) {
  string *owners, owner, ownee, owned;
  int i, code, iid;

  if(!doornum && environment(this_player())->is_saveable()) return 1;

  code = 1;
  owners = read_file("/data/castle/owner_list");
  owner = explode(owners, "\n");

  for(i=0; i<sizeof(owner); i++) {
    sscanf(owner[i], "%s:%d", ownee, owned);
    iid = environment(this_player())->query_castle_id();
    if(owned == iid) {
      if(capitalize(this_player()->query_name()) == ownee) code = environment(this_player())->query_door_code(doornum);
    }
  }
  if(this_player()->query_wiz()) write("doorcode: "+code+"\n");
  return code;
}

write_key(kode) {
  int key_id, i, last, old_code;
  string key_file, tmp, t2, t1;
  object key_ob;

  while(file_size(keys_file+i+".c") != -1) {
    i++;
    last = i;
  }

  for(i=0; i<last; i++) {
    sscanf(read_file(keys_file+i+".c") , "%skey_code(\"%d\")%s", t1, old_code, t2);
    if(!key_id) { if(old_code == kode) key_id = i; }
  }

  if(!key_id) {
    key_id = last;

    key_file = keys_file+key_id+".c";
    write_file(key_file, "inherit \"room/key\";\n");
    write_file(key_file, "inherit \"castle/obj/key_base\";\n");
    write_file(key_file, "reset() { set_key_code(\"+kode+\"); }\n");
  }
  return keys_file+key_id;
}
 
create_key(arg) {
  int num, koodi;
  string key;
  object key_ob;

  if(!arg) return;

  if (!sscanf(arg, "key for door %d",num)) {
    if (arg != "key for door") {
      write("Usage: duplicate key for <door>\n");
      return 1;
    }
  }

  if(num == 0) num = 1;

  koodi = environment(this_player())->query_door_code(num);
  key = write_key(koodi);
  key_ob = clone_object(key);
  move_object(key_ob, this_player());
  write("Key created.\n");

  return 1;
}

void init() {
  add_action("owner", "owner");
  add_action("create_key", "duplicate");
}
