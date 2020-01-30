inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/guard");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/mosquec2");
  add_exit("west","wizards/nalle/jerusalem/mosqueb1");
  add_exit("east","wizards/nalle/jerusalem/mosqueb3");
  add_exit("out","wizards/nalle/jerusalem/mosc3");
  short_desc = "The Mosque";
  long_desc =
"The mosque you have entered is built of chalkstone and\n" +
"cement. The air here smells a bit like sand and it is much\n" +
"cooler here than outside. The chanting of the praying\n" +
"reaches your ears, and echoes eerily from the think stone\n" +
"walls of the mosque. \n";
}

