inherit "room/room";
 
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/aijys1");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("out","wizards/nalle/jerusalem/chrc1");
  short_desc = "A small house";
  long_desc =
"You have entered a small house in the Christian Quarter\n" +
"of Jerusalem. The house is actually not a house but a room\n" +
"which is very modeslty decorated. A young man is sitting\n" +
"in a corner of the house, looking quite depressed.\n";
}
