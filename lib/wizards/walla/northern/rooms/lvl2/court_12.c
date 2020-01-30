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
  add_exit("north","court_22");
  add_exit("west","court_11");
  add_exit("south","cell_10");
  add_exit("east","court_13");
  short_desc = "In the courtyard";
  long_desc =
"You are standing in the corner of the castle's courtyard. The ground is covered \n"+
"with sawdust, that has been tainted red, from the live practice that the dwarves\n"+
"do. You notice that barracks surround the entire area. You can see battle drills\n"+
"going on in the courtyard and clattering sounds of armour and talking can be heard\n"+
"from inside the barracks.\n";
 
}

