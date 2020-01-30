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
  add_exit("north","cell_4");
  add_exit("west","court_34");
  add_exit("south","court_25");
  add_exit("east","cell_5");
  short_desc = "In the courtyard";
  long_desc =
"You are standing in the corner of the castle's courtyard. The ground is covered \n"+
"with sawdust, that has been tainted red, from the live practice that the dwarves\n"+
"do. You notice that barracks surround the entire area. You can see battle drills\n"+
"going on in the courtyard and clattering sounds of armour and talking can be heard\n"+
"from inside the barracks.\n";
 
}
