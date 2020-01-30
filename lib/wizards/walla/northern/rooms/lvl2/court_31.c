inherit "room/room";
 
 
reset(arg) {
 
  add_exit("north","stairs_d");
  add_exit("south","court_21");
  add_exit("east","court_32");
  add_exit("west","cell_14");
  short_desc = "In the courtyard";
  long_desc =
"You are standing in the corner of the castle's courtyard. The ground is covered \n"+
"with sawdust, that has been tainted red, from the live practice that the dwarves\n"+
"do. You notice that barracks surround the entire area. You can see battle drills\n"+
"going on in the courtyard and clattering sounds of armour and talking can be heard\n"+
"from inside the barracks.\n";
 
}
