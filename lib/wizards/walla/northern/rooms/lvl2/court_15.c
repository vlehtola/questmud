inherit "room/room";
 
 
reset(arg) {
 
  add_exit("north","court_25");
  add_exit("south","stairs_u");
  add_exit("east","cell_7");
  add_exit("west","court_14");
  short_desc = "In the courtyard";
  long_desc =
"You are standing on one side of the castle's courtyard. The ground is covered \n"+
"with sawdust, that has been tainted red, from the live practice that the dwarves\n"+
"do. You notice that barracks surround the entire area. You can see battle drills\n"+
"going on in the courtyard and clattering sounds of armour and talking can be heard\n"+
"from inside the barracks.\n";
 
}
