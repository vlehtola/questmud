inherit "room/room";
 
 
reset(arg) {
 
  add_exit("north","court_34");
  add_exit("south","court_14");
  add_exit("east","court_25");
  add_exit("west","flagstaff");
  short_desc = "In the courtyard";
  long_desc =
"You are standing in castle's courtyard. The ground is covered with sawdust, that\n" +
"has been tainted red, from the live practice that the dwarves do. You notice that barracks \n" +
"surround the entire area. You can see battle drills going on in the courtyard and clattering sounds\n" +
"of armour and talking can be heard from inside the barracks.\n";
 
}