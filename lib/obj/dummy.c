string name;

reset(arg) {
  if (arg) { return; }
  name = "dummy"; set_living_name(name); enable_commands();
}
init() {
  add_action("test", "test");
}

test(arg) {
  object ob;
  if(!arg) return;
  ob = present(arg,environment(this_object()));
  if(!ob) return;
  ob->attack_object(this_object());
  return 1;
}

id(str) {
    return str == name;
}

query_name() { return name; }

query_max_hp() { return 10000; }
long() {
    write("This is a test dummy. It reports the damage done.\n");
}

short() {
    return "A test dummy";
}

hit_player(dam, dam_type, ob) {
  int d,da;
  if (dam) {
    if (dam_type == 0) { dam_type = 1; }
    d = dam;
    da = dam_type;
    say("Dummy says: 'OUCH! That did " + d + " points of " + da + " damage.'\n");
    return d;
  }
  if ( ob && !(ob->query_wiz() || ob->query_tester()) ) {
    ob->death();
    if ( find_player("rag") ) {
      tell_object(find_player("rag"),ob->query_name()+" has the dummy.\n");
    }
  }
}

hit_with_spell(dam, dam_type, ob) {
  int d,da;
  if (dam) {
    if (dam_type == 0) { dam_type = 1; }
    d = dam;
    da = dam_type;
    say("Dummy says: 'OUCH! That did " + d + " points of " + da + " damage.'\n");
    return d;
  }
  if ( ob && !(ob->query_wiz() || ob->query_tester()) ) {
    ob->death();
    if ( find_player("rag") ) {
      tell_object(find_player("rag"),ob->query_name()+" has the dummy.\n");
    }
  }
}

query_attack() { return this_player(); }
