inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(14 + random(3));
  set_name("snow golem");
  set_alias("golem");
  set_short("A snow golem");
  set_long("This creature could easily be mistaken for a snowman. The golem stands\n" +
           "still on the ground. Seems that it has not got any commands from its\n" +
           "summoner. Snow golem's body consists thoroughly of snow. Though the\n" +
           "material, from which the golem has been made of, is soft, the golem is\n" +
           "still a ferocious enemy because of the wide knowledge of how to fight\n" +
           "if needed.\n");

  set_resists("cold", 80);
}