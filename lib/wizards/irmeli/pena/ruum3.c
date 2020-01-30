inherit "room/room";
object monster;

reset(arg) {
  if(!present("angel 3")) { 
    move_object(clone_object("/wizards/irmeli/pena/angelfig.c"),
    this_object());
    move_object(clone_object("/wizards/irmeli/pena/angelfig.c"), 
    this_object());
    move_object(clone_object("/wizards/irmeli/pena/angelfig.c"),
    this_object());
}
  
  if(arg) return;

  add_exit("west","/wizards/irmeli/pena/ruum4.c");
  add_exit("east","/wizards/irmeli/pena/ruum5.c");
  add_exit("south","/wizards/irmeli/pena/ruum2.c");

  short_desc = "Dusty path in the begin of the Valley of Angels";
  long_desc = "You are walking on path leading deeper into the Valley of Angels. You can\n"+
                "hear noises coming all around you. There are some heads hanging\n"+
                "on trees. There are a few rocks lying on the path.\n";   
}


