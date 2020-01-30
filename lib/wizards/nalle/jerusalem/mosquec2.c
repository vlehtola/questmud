inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/mosconduct");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("west","wizards/nalle/jerusalem/mosquec1");
  add_exit("east","wizards/nalle/jerusalem/mosquec3");
  add_exit("south","wizards/nalle/jerusalem/mosqueb2");
  short_desc = "The mosque";
  long_desc =
"This seems to be the place from which the chanting and\n" +
"praying is conducted. A man clad in white cotton cloaks\n"+
"and a turban is taking care of the job right now, despite the\n" +
"small amount of people attending to the prayers.\n";
}

