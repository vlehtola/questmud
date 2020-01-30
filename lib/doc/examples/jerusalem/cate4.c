inherit "room/room";
object monster;
reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/priest");
    move_object(monster, this_object());
  }
if(arg) return;
  add_exit("west","wizards/nalle/jerusalem/cate3");
  add_exit("east","wizards/nalle/jerusalem/cate5");
  add_exit("south","wizards/nalle/jerusalem/catd4");
  add_exit("north","wizards/nalle/marriage/marriage_room");
  short_desc = "At the altar";
  long_desc =
"You are in the middle of main hall of the cathedral, right\n" +
"infront of the altar. A priest is preaching behind it right this\n" +
"moment, but you can not make out much of what he says. The\n" +
"monks sitting on the benches look at you quizzically.\n";
}

