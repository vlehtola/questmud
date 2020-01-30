inherit "/obj/monster";

reset(status arg) {
  ::reset(arg);
  if(arg) return;
  set_level(50);
  set_name("minion");
  set_short("A minion");
}

add_exp(int i, string str, mixed arg) {
  object ob;
  ob = find_player("celtest");
  if(!ob) return;
  tell_object(ob, "Minion whispers to you, 'I just proxied "+i+" xp to you, Master.'\n");
  ob->add_exp(i, str, arg);
}

init() {
  add_action("target_mob", "target");
}

target_mob(string arg) {
  object ob;
  ob = present(arg, environment(this_object()) );
  if(!ob) {
    write("fail.\n");
    return 1;
  }
  write("Attacking\n");
  this_object()->attack_object(ob);
  return 1;
}
