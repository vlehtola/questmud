string id, short, long, name;
int a, sealed;

set_short(arg) {
  short = arg;
}

set_long(arg) {
  long = arg;
}

short() {  
  return short;
}
  
long() {
  write(long+".\n");
}

set_name(arg) {
  name = arg;
}

get() {
  if(!sealed) return 1;
}

id(str) { return str == name; }

seal(arg) {
  object items;
  int count, i;

  if(!arg) {
    write("Usage: seal <item>\n");
    return 1;
  }
  if(present(arg) != this_object()) return;

  items = all_inventory(environment(this_object()));
  for(i=0; i<sizeof(items); i++) {
    if(!living(items[i])) count++;
  }

  if(count > 20) {
    write("There is no more room for this to be saved, remove something from room first.\n");
    return 1;
  }

  if(sealed) {
    write(short()+" is already secured in this room.\n");
    return 1;
  }
  if(environment(this_object())->is_saveable() != 1) {
    write("There is no place in this room for it to be sealed.\n");
    return 1;
  }

  write("You secure "+short()+".\n");
  sealed = 1;
  environment(this_object())->save_room();
  return 1;
}

unseal(arg) {
  if(!arg) {
    write("Usage: unseal <item>\n");
    return 1;
  }
  if(present(arg) != this_object()) return;
  if(!sealed) {
    write(short()+" is not secured in this room.\n");
    return 1;
  }

  write("You remove securing from "+short()+".\n");
  sealed = 0;
  environment(this_object())->save_room();
  return 1;
}

is_castleitem() {
  return sealed;
}

init() {
  add_action("seal", "seal");
  add_action("unseal", "unseal");
}
