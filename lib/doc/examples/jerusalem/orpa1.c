inherit "room/room";

object monster,monster2;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/orphan");
    move_object(monster, this_object());
  }
if(!monster2) {
    monster2 = clone_object("/wizards/nalle/jerusalem/monsters/orphan");
    move_object(monster2, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/orpb1");
  add_exit("east","wizards/nalle/jerusalem/orpa2");
  short_desc = "In the dormatory part of the orphanage";
  long_desc =
"This is the western side of the orphanage. There are quite\n" +
"a few beds here and this part of the building is obviously\n" +
"used as a dormatory. Despite the smell of greasy drapes\n" +
"and the cockroaches the quality of living in this facility\n" +
"exceeds that of most mediocre inns. \n";
}

