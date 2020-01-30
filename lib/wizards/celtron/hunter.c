inherit "obj/monster";
object victim;

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("demon");
    set_alias("hunter");
    set_short("A demon hunter");
    set_long("A HUGE demon hunter is ready to tear it's victims apart.\n"+
	"Give it a victim by typing: target <name>\n");
    set_level(random(20)+10);
    set_aggressive(0);
    set_al(-100);
    set_mage();
}

init() {
  add_action("start_hunt", "target");
  add_action("destruct", "destruct");
}

destruct() {
  write("What ?\n");
  return 1;
}

start_hunt(str) {
  if (!str) {
    write("Demon says: 'yeayea, tell me the fucking target!'\n");
    return 1;
  }
  if(victim) {
    write("Demon is busy already.\n");
    return 1;
  }
  victim = find_player(str);
  if (!victim) {
    write("Demon shrugs and screams: 'Tell me the real target, damned!'\n");
    return 1;
  }
  call_other("/wizards/celtron/shadow", "start", this_object());
  write("Demon grins evilly and winks.\n");
  call_out("check", 0);
  return 1;
}

check() {
  object ob;
  string msg;
  if (!present(victim)) {
    say("The demon runs after it's victim!\n");
    move_object(this_object(), environment(victim));
    say("The demon rushes in!\n");
    this_object()->attack_object(victim);
    call_out("check", 1);
    return 1;
  } else if (random(2) == 1) {
    msg = "Demon screams: 'Die you unrighteous!'";
  } else {
    msg = "Demon yells: 'Come here brothers, I have located him!'";
  }
  ob = first_inventory(environment(this_object()));
  while(ob) {
    if (living(ob)) {
      tell_object(ob, msg + "\n");
    }
    ob = next_inventory(ob);
  }
  call_out("check", 0);
}






