inherit "room/room";

object monster;

reset(arg) {
    if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/bishop");
    move_object(monster, this_object());
 } 
  if(arg) return;
  add_exit("south","wizards/nalle/jerusalem/catbishop");
  short_desc = "In the bishop's quarters";
  long_desc =
"These are the bishops quarters. Paintings are hung on the walls and a \n" +
"there is a beautiful oaken desk in the back of the room. The bishop is\n" +
"standing on an eastern carpet in the middle of the room.\n";
}
