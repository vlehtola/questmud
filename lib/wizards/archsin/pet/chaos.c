inherit "obj/monster";

int follow;

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(667);
  set_name("chaos");
  set_alias("demon");
  set_short("Chaos, father of the gods");
  set_long("Chaos. The father of the gods is standing here, watching.\n");
  set_aggressive(0);
  set_random_pick(0);
  set_regen(query_max_hp()/20);
  set_resists("physical", 99);
  set_resists("fire", 99);
  set_block_message("The guard standing before the exit blocks your way.");
  set_regen(query_max_hp()/5);
  set_max_hp(query_max_hp()*10);
  set_str(query_str()*100);
  set_gender(1);
  set_block_dir("east");
}

countries() {
  object list;
  string temp, finn, swee, comm, nett, unkk;
  int i, fin, swe, com, net, unk;
  mapping who;
  who = ([ ]);

  finn = "";
  swee = "";
  comm = "";
  nett = "";
  unkk = "";

  if(this_player()->query_name() != "Archsin") return;

  write("\nCountries:\n");
  write("----------\n");

  list = users();
  for(i=0; i<sizeof(list); i++) {
    temp = explode(query_ip_name(list[i]), ".");
    switch(temp[sizeof(temp)-1]) {
    case "fi":
      fin++;
      finn += capitalize(list[i]->query_name())+" ";
      break;
    case "se":
      swe++;
      swee += capitalize(list[i]->query_name())+" ";
      break;
    case "com":
      com++;
      comm += capitalize(list[i]->query_name())+" ";
      break;
    case "net":
      net++;
      nett += capitalize(list[i]->query_name())+" ";
      break;
    default:
      unk++;
      unkk += capitalize(list[i]->query_name())+" ";
    }
  }
  write(".fi ("+fin+"): "+finn+"\n");
  write(".se ("+swe+"): "+swee+"\n");
  write(".com ("+com+"): "+comm+"\n");
  write(".net ("+net+"): "+nett+"\n");
  write(".??? ("+unk+"): "+unkk+"\n");

  return 1;
}

order(arg) {
  string cmd, temp_cmd, param;

  if(this_player()->query_name() != "Archsin") return;

  if(sscanf(arg, "chaos to %s", cmd) != 1) return;

  if(sscanf(cmd, "%s %s", temp_cmd, param) == 2) cmd = temp_cmd;

  switch(cmd) {
  case "follow":
    write("Chaos says: 'Ok, following.'\n");
    follow = 1;
    break;
  case "hold":
    write("Chaos says: 'Ok, holding here.'\n");
    follow = 0;
    break;
  case "block":
    if(!param) {
      write("Chaos says 'Block what?'\n");
      return 1;
    }
    set_block_dir(param);
    write("Chaos says 'Blocking now "+param+"'\n");
    break;
  default:
    write("Chaos says: 'What?'\n");
  }
  return 1;
}


block_move() {
  // modified by Celtron
  switch(this_player()->query_name()) {
    case "Siki":
    case "Nalle":
    case "Bloodstorm":
    write("Chaos says 'You may pass.'\n");
    return;
    default:
    write("Chaos says 'You may not pass.'\n");
    return 1;
  }
}

void init() {
  ::init();
  add_action("order", "order");
  add_action("countries", "countries");
}

void heart_beat() {
  ::heart_beat();
  if(!present("archsin", environment(this_object())) && find_player("archsin") && follow) {
    say(capitalize(name)+" goes away.\n");
    move_object(this_object(), environment(find_player("archsin")));
    say(capitalize(name)+" arrives.\n");
  }
}

catch_tell(str) {
  string tmp1,tmp2;
  object ob;
  if (sscanf(str, "%s says '%s'", tmp1, tmp2) == 2) {
    ob = find_player("archsin");
    if (!ob) { return; }
    tell_object(ob, "[Chaos]: "+tmp1+" says: '"+tmp2+"'\n");
  }
}
