inherit "room/room";
object monster;

reset(arg) {
  if(!present("hobbit 2")) { 
    move_object(clone_object("/wizards/irmeli/area2/hobbit2.c"),
    this_object());
    move_object(clone_object("/wizards/irmeli/area2/hobbit2.c"), 
    this_object());
}  

  if(arg) return;

  add_exit("south","/wizards/irmeli/area2/ruum8.c");
  set_not_out(1);
  
  short_desc = "Second level in hobbit mine";
  long_desc = "You made your way to the second level of this mine. The abyss elevator\n"+
                "shaft continues to down next to your feets. You can hear the sound\n"+
                "of the elevator somewhere near you. Cold air flows in from lower\n"+   
                "levels making you shiver.\n";
}

