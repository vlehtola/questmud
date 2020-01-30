inherit "room/room";

reset(arg) {
 if(!present("guard")) {
   move_object(clone_object("/wizards/morgoth/town/npc/guard"),
this_object());
 }
 if(!present("guard")) {
   move_object(clone_object("/wizards/morgoth/town/npc/guard"),
this_object());
 }
  if(arg) { return; }
  add_exit("leave", "/wizards/morgoth/town/rooms/outworld.c");
  add_exit("south", "/wizards/morgoth/town/rooms/room2.c");
  short_desc = "The gates to the Boonooroo.";
  long_desc = "You have come to the town gates of Boonooroo.\n"+ 
              "Guards are usually posted here to keep out those evil bandits\n"+
              "that cause a havoc. You can see a small quaint town beyond these\n"+ 
              "gates. The town appears to be doing well, by normal standards.\n";
 }
