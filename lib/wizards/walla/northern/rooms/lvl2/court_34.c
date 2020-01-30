inherit "room/room";
 
object monster,monster2;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/northern/mobs/conscript2");
    move_object(monster, this_object());
  }
 
  if(!monster2) {
    monster2 = clone_object("/wizards/walla/northern/mobs/sergeant");
    move_object(monster2, this_object());
  }
 
  if(arg) return;
  add_exit("north","cell_3");
  add_exit("west","court_33");
  add_exit("south","court_24");
  add_exit("east","court_35");
  short_desc = "In the courtyard";
  long_desc =
"You are standing in the castle's courtyard. The ground is covered with sawdust, that\n" +
"has been tainted red, from the live practice that the dwarves do. You notice that barracks \n" +
"surround the entire area. You can see battle drills going on in the courtyard and clattering sounds\n" +
"of armour and talking can be heard from inside the barracks.\n";
 
}
