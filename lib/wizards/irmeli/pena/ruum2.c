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

  add_exit("north","/wizards/irmeli/pena/ruum3.c");
  add_exit("south","/wizards/irmeli/pena/ruum1.c");
 
  short_desc = "Dusty path in the begin of the Valley of Angels.";
  long_desc = "You are walking on path leading deeper into Valley of Angels. There is a\n"+
                "small lake in front you. Trees are very old and covered with old\n"+
                "blood. There are some spiders walking on the path.\n";   
}



