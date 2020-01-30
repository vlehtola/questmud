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
  add_exit("south","wizards/nalle/jerusalem/orpa1");
  add_exit("east","wizards/nalle/jerusalem/orpb2");
  short_desc = "In the dormatory part of the orphanage";
  long_desc =
"This is the western end of the orphanage.You are at\n" +
"the northern end of the dormatory part of it. There is\n" +
"a long row of beds against this wall and they seem pretty\n" +
"clean too. The row of beds continues south and to your\n" +
"east you notice some desks and other furniture. \n";
}

