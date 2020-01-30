inherit "room/room";
object monster;

reset(arg) {
  if(!present("hobbit 2")) { 
    move_object(clone_object("/wizards/irmeli/area2/hobbit7.c"),
    this_object());
    move_object(clone_object("/wizards/irmeli/area2/hobbit7.c"), 
    this_object());
}  

  if(arg) return;

  add_exit("south","/wizards/irmeli/area2/ruum27.c");
  add_exit("north","/wizards/irmeli/area2/ruum23.c");
  set_not_out(1);
 
  short_desc = "Room of where kings guards lives";
  long_desc = "This is a tiny room where the kings guards live. There are two guardhuts in\n"+
                "front you in the middle of this room. There is a small campfire burning next\n"+
                "to the guardhuts.\n";   
}


