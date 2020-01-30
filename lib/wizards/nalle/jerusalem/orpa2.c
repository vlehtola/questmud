inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/grkeeper");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/orpb2");
  add_exit("west","wizards/nalle/jerusalem/orpa1");
  add_exit("east","wizards/nalle/jerusalem/orpa3");
  add_exit("out","wizards/nalle/jerusalem/mosb1");
  short_desc = "The entrance to the orphanage";
  long_desc =
"You have entered the orphanage situated in the Moslem\n" +
"quarter of Jerusalem. The orphanage seems to be a pretty\n" +
"large rectangular building with a long row of beds on the\n" +
"western wall of the building, and tables that are used for\n" +
"eating and education on the eastern side of the building. \n";
}

