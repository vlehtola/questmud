#define UPGRADE_COST 40
 // 40

string owner, name, alias, short_desc, long_desc, guard, guard_file;
int level, guard_id;

reset(arg) {
  if(arg) { return; }
  level = 10;
  name = "figurine";
  short_desc = "Small figurine";
  long_desc = "A figurine of castle guard.\n";
  guard = "castle/obj/castle_guard.c";
}

set_level(arg) {
  level = arg;
}

get() {
  return 1;
}

set_guardfile(arg) {
  guard = arg;
}

set_name(arg) {
  name = arg;
}

set_alias(arg) {
  alias = arg;
}

set_short(arg) {
  short_desc = arg;
}

short() {
  string str;
  str = short_desc;
  return str;
}

set_long(arg) {
  short_desc = arg;
}

long() {
  string str;
  str = long_desc;
  write(str);
}

id(str) { if(str == name) return 1; }

morph(arg) {
  int number, dummy, count, i;
  string fname, *list;
  object ob;

  if(!arg) return;
  if(present(arg) != this_object()) return;
  if(!environment(this_object())->is_saveable()) {
    if(environment(this_player())->is_saveable()) {
      write("You must put "+short()+" to ground first.\n");
      return 1;
    }
    write("Guards are for castles only.\n");
    return 1;
  }
  if(environment(this_object())->query_owner() != capitalize(this_player()->query_name())) {
    write("This is not your castle.\n");
  }
  list = all_inventory(environment(this_object()));
  for(i=0; i<sizeof(list); i++) {
    if(list[i]->is_guard()) count++;
  }
  if(count >= 10) {
    write("There are too many guards in this room.\n");
    return 1;
  }

  ob = clone_object(guard);
  ob->set_level(level);
  ob->set_owner(this_player()->query_name());
  move_object(ob, environment(this_player()));
  guard_id = get_guard_id();
  ob->force_set_id(guard_id);
  ob->set_random_pick(0);
  ob->tune_up();
  ob->save(environment(this_player())->give_me_path()+"/guard_"+guard_id);

  write("The figurine morphs into it's full shape, into "+ob->short()+"\n");
  say(this_player()->query_name()+" does something with figurine. Before you notice, there's a "+ob->short()+" standing in the center of this room.\n");

  sscanf(file_name(environment(this_object())), "%s/castle_%d/room%d", fname, number, dummy);
  guard_file = fname+"/castle_"+number+"/guards";
  write_file(guard_file, "15"+":"+guard+":"+level+":"+file_name(environment(this_player()))+"\n");

  environment(this_object())->create_guard_file();
  destruct(this_object());
  return 1;
}

get_guard_id() {
  int i, number, iidee, dummy, between, free_id, guard_level, g_id;
  string fname, this_room, guard_file, guard_path;
  string tfile, *tlist;

  this_room = file_name(environment(this_object()));

  sscanf(this_room, "%s/castle_%d/room%d", fname, number, dummy);
  guard_file = fname+"/castle_"+number+"/guards";

  //  write("guard_file: "+guard_file+"\n");

  if(file_size(guard_file) == -1) write_file(guard_file, "\n");

  tfile = read_file(guard_file);
  tlist = explode(tfile, "\n");

  if(iidee == 0) {
    for(i=0; i<sizeof(tlist); i++) {
      sscanf(tlist[i], "%d:%s:%d:%s", g_id, guard_file, guard_level, guard_path);
      free_id = g_id+1;
      if(g_id != i) between = i;
    }
    iidee = free_id;
    if(between > 0) iidee = between;
  }
  return iidee;
}

tune(str) {
  string who, cmd, arg;
  int new_level, cost;
  object target;

  if(!str) {
    write("Usage: upgrade [figurine] [parameter] to [arg]\n");
    return 1;
  }
  if(sscanf(str, "%s %s to %s", who, cmd, arg) != 3) {
    if(sscanf(str, "%s %s", who, cmd) != 2) {
      write("Usage: upgrade [figurine] [parameter] to [arg]\n");
      return 1;
    }
  }

  if(present(who) != this_object()) return;

  target = present(who);

  switch(cmd) {
  case "level":
    new_level = to_int(arg);
    if(new_level <= level) {
      write("You cannot downgrade guards.\n");
      return 1;
    }
    if(new_level > 100) {
	  write("You cannot upgrade guards more then 100 level.\n");
	  return 1;
    }
    cost = (new_level * new_level * UPGRADE_COST) - (level * level * UPGRADE_COST);
    if(this_player()->query_money(3) < cost) {
      write("You do not have '"+cost+"' bronze coins!\n");
      return 1;
    }
    this_player()->reduce_money(cost, 3);
    level = new_level;
    write("You pay "+cost+" bronze coins for the upgrade.\n");
    write(target->short()+"'s level upgraded to '"+level+"'\n");
    break;
  default:
      write("Usage: upgrade [figurine] [parameter] to [arg]\n");
  }
  return 1;
}

info(arg) {
  if(!arg) return;
  if(present(arg) != this_object()) return;

  write(short()+"\n");
  write("level: "+level+"\n");

  if(!this_player()->query_wiz()) return 1;

  write("id: "+guard_id+"\n");
  return 1;
}

init() {
  add_action("tune", "upgrade");
  add_action("morph", "morph");
  add_action("info", "info");
}
