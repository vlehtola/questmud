inherit "/obj/monster";

int id, repop_chance;
string owner, *friends;

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(1);
  set_name("guard");
  set_alias("castle guard");
  set_short("Castle guard");
  set_long("A castle guard.\n");
  set_aggressive(0);
  set_block_message("The guard standing before the exit blocks your way.");
  repop_chance = 50;
  set_regen(query_max_hp()/20);

  friends = allocate(20);
}

tune_up() {
  set_max_hp(query_max_hp()*30);
  set_hp(query_max_hp());
  set_str(query_str() * 7);
  set_random_pick(0);
  set_regen(query_max_hp()/20);
  set_exp(1);
}

query_id() {
  return id;
}

second_life() {
  repop_chance = 50+this_object()->query_level();
  if(random(100) < repop_chance) {
    tell_room(environment(this_object()), "Ghost of "+this_object()->query_name()+" shrikes a spine chilling cry, giving you the creeps..\n");
    call_other("/castle/obj/castle_guard", "midplop", this_object()->query_guard(), this_object()->query_level(), environment(this_object()), this_object()->query_id(), environment(this_object())->give_me_path());
  }
}

midplop(guard, level, where, id, castle) {
  call_out("replop", random(2250)+1350, guard, level, where, id, castle);
}

replop(guard, level, where, id, castle) {
  int number, dummy;
  object ob;

//  tell_room(environment(this_object()), this_object()->query_name()+" walks in.\n");

  ob = clone_object(guard);
  ob->set_level(level);
  ob->set_exp(1);
  ob->force_set_id(id);
  sscanf(castle, "/data/castle/castle_%d/room%d", number, dummy);
  ob->restore("/data/castle/castle_"+number+"/guard_"+id);
  move_object(ob, where);
}

morph(arg) {
  int number, dummy;
  string fname, cown, own, tpla;
  object ob;

  if(!arg) return;
  if(present(arg) != this_object()) return;

  if(tpla == own || tpla == cown ) { write("morphing..\n"); }
  else {
    write("That is not your guard.\n");
    return 1;
  }

  ob = clone_object("/castle/obj/castle_guard_figurine");
  ob->set_level(query_level());
  ob->set_owner(owner);
  move_object(ob, this_player());

  rm(environment(this_object())->give_me_path()+"/guard_"+id);

  write("The guard morphs back into small figurine.\n");
  say(this_player()->query_name()+" does something with guard. Before you notice, the "+this_object()->query_name()+" is gone.\n");

  environment(this_object())->create_guard_file();

  destruct(this_object());
  return 1;
}

is_guard() {
  return 1;
}

query_guard() {
  string guard;

  guard = explode(file_name(this_object()), "#");
  return guard[0];
}

restore(restore_file) {
  restore_object(restore_file);
}

save(save_file) {
  save_object(save_file);
}

force_set_id(arg) {
  id = arg;
}

void set_owner(string arg) {
  owner = arg;
}

int show_friends() {
  int i, empty;
  empty = 1;
  for(i=0; i<sizeof(friends); i++) {
    if(friends[i] != 0) empty = 0;
  }
  if(empty) {
    write("Allowing no-one to pass.\n");
    return 1;
  }
  write("Allowing following players to pass: \n");
  for(i=0; i<sizeof(friends); i++) {
    if(friends[i] != 0) write("  "+capitalize(friends[i])+"\n");
  }
  return 1;
}

block_move() {
  int i;

  for(i=0; i<sizeof(friends); i++) {
    if(friends[i] == lower_case(this_player()->query_name())) {
      return 0;
    }
  }

  if(lower_case(this_player()->query_name()) == lower_case(owner)) return 0;

  if (block_message) {
    write(block_message + "\n");
    return 1;
  }
  write(capitalize(this_object()->query_name()) + " blocks your way.\n");
  return 1;
}

void compress(string rem) {
  string *temp;
  int i, k;
  temp = allocate(21);
  k = 0;
  for(i=0; i<sizeof(friends); i++) {
    if(friends[i] != rem) {
      temp[k] = friends[i];
      k++;
    }
  }
  friends = temp;
}

allow(arg) {
  int i;
  object plr;
  i = 0;

  if(!arg) {
    write("Usage: allow <player>.\n");
    return 1;
  }
  if(!plr = find_player(lower_case(arg))) {
    write("No player "+capitalize(arg)+" here!\n");
    return 1;
  }

  count = 0;

  if(present(plr)) {
    while(friends[i]) i++;
    if(count >20) {
      write("Sir, I can't remember anymore who to allow, remove someone from list first, Sir.\n");
      return 1;
    }
    tell_object(this_player(), "Sir, allowing "+capitalize(arg)+" to pass until further notice, Sir.\n");
    count++;
    friends[i] = lower_case(arg);
  }
  else {
    tell_object(this_player(), "Sorry Sir, can't see "+capitalize(arg)+" here, Sir.\n");
  }
  return 1;
}

ban(arg) {
  int match, i;

  if(arg) {
    for(i=0; i<sizeof(friends); i++) {
      if(friends[i] == lower_case(arg)) {
	compress(friends[i]);
	tell_object(this_player(), "Sir, "+capitalize(arg)+" is now banned, Sir.\n");
	return 1;
      }
    }
    tell_object(this_player(), "Sir, no-one named '"+capitalize(arg)+"' is on my allow list, Sir.\n");
    return 1;
  }
  else write("Usage: ban <player>.\n");
  return 1;
}

block(arg) {
  if(!arg) {
    write("Usage: block <dir>.\n");
    return 1;
  }
  if(arg == "out") {
    write("Sir, won't block the only way out, find better place for your deathtrap, Sir.\n");
    return 1;
  }

  set_block_dir(arg);
  tell_object(this_player(), "Sir, blocking '"+arg+"', Sir.\n");
  return 1;
}

order(str) {
  string who, cmd, arg;
  object target;

  if(!str) {
    write("Usage: order [guard] to [cmd] [arg]\n");
    return 1;
  }

  if(lower_case(this_player()->query_name()) != lower_case(owner)) return;

  if(sscanf(str, "%s to %s %s", who, cmd, arg) != 3) {
    if(sscanf(str, "%s to %s", who, cmd) != 2) {
      write("Usage: order [guard] to [cmd] [arg]\n");
      return 1;
    }
  }

  if(present(who) != this_object()) return;

  if(!who) {
    write("Usage: order [guard] to [cmd] [arg]\n");
    return 1;
  }
  if(!cmd) {
    write("Usage: order [guard] to [cmd] [arg]\n");
    return 1;
  }
  target = present(who);

  switch(cmd) {
  case "block":
    target->block(arg);
    break;
  case "list":
    target->show_friends();
    break;
  case "allow":
    target->allow(arg);
    break;
  case "ban":
    target->ban(arg);
    break;
  default:
    write("Unknown command, valid commands are: allow, ban, block, and list.\n");
  }
  save(environment(this_player())->give_me_path()+"/guard_"+id);
  return 1;
}

catch_tell(arg) {
  string who, what;

  if(sscanf(arg, "%s attacks %s!", who, what) == 2) {
    if(lower_case(what) == lower_case(owner) || lower_case(what) == "guard") {
      if(find_player(lower_case(owner))) tell_object(find_player(lower_case(owner)), "["+name+"] "+who+" just attacked "+lower_case(what)+"!\n");
      if(present("guard 2")) say("Guard says 'Come on pal's, lets slice this wimp!'\n");
      attack_object(present(lower_case(who)));
    }
  }
  if(sscanf(arg, "%s starts working on chests sealing.", who)) {
    if(present(lower_case(who))) {
      tell_object(owner, "["+query_name()+"] "+who+" just started to forcing a chest here!\n");
      say("Guard shouts 'Hey, you there! No you dont!'\n");
      attack_object(present(lower_case(who)));
      if(present("guard 2")) say("Guard says 'Come on pal's, lets slice this wimp!'\n");
    }
  }
  if(sscanf(arg, "%s starts pounding the door.", who)) {
    if(present(lower_case(who))) {
      tell_object(find_player(lower_case(owner)), "["+query_name()+"] "+who+" just started pounding a door here!\n");
      say("Guard shouts 'Hey, You there! No you dont!'\n");
      attack_object(present(lower_case(who)));
      if(present("guard 2")) say("Guard says 'Come on pal's, lets slice this wimp!'\n");
    }
  }
  if(sscanf(arg, "%s starts concentrating on an offensive spell.", who)) {
    if(present(lower_case(who))) {
      tell_object(find_player(lower_case(owner)), "["+query_name()+"] "+who+" just started casting offensive spell!\n");
      say("Guard shouts 'Hey, you there! No you dont!'\n");
      attack_object(present(lower_case(who)));
      if(present("guard 2")) say("Guard says 'Come on pal's, lets slice this wimp!'\n");
    }
  }
}

info(arg) {
  if(!arg) return;
  if(present(arg) != this_object()) return;

  write(short()+"\n");
  write("level: "+level+"\n");
  write("block dir: "+block_direction+" ");
  if(!this_player()->query_wiz()) return 1;

  write("id: "+id+"\n");
  write("owner: "+owner+"\n");
  return 1;
}

void init() {
  ::init();
  add_action("morph", "morph");
  add_action("info", "info");
  add_action("order", "order");
}