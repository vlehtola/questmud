inherit "room/room";
 
 
reset(arg) {
 
  add_exit("north","court_31");
  add_exit("south","court_11");
  add_exit("east","court_22");
  add_exit("west","cell_13");
  short_desc = "In the courtyard";
  long_desc =
"You are standing in the western part of the castle's courtyard. The ground is covered with sawdust, that\n" +
"has been tainted red, from the live practice that the dwarves do. You notice that barracks \n" +
"surround the entire area. You can see battle drills going on in the courtyard and clattering sounds\n" +
"of armour and talking can be heard from inside the barracks.\n";
 
}
