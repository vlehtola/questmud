inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(40 + random(6));
  set_name("seashell");
  set_alt_name("shell");
  set_short("An angry-looking seashell is shivering quickly");
  set_long("Angry, white seashell is shivering quickly while floating on one spot.\n" +
           "Now and then the seashell clamps its shells against each other like trying\n" +
           "to scare away its possible enemies. The seashell seems to be guarding some\n" +
           "kind of a underwater cave.\n");
  set_aggressive(1);
  set_animal();
  set_str(query_str() + 50);
  set_skill("dodge", 50);
  set_skill("alertness", 50);
  set_skill("foresee attack", 30);
  set_skill("tumble", 40);
  set_log();
  set_al(-20);
}

secname() {
  set_short("A white seashell is clamping its shells madly");
  set_level(25 + random(6));
}
