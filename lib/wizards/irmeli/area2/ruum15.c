inherit "room/room";
object monster;

reset(arg) {
  if(!present("hobbit 2")) {
    move_object(clone_object("/wizards/irmeli/area2/hobbit3.c"),
    this_object());
    move_object(clone_object("/wizards/irmeli/area2/hobbit3.c"),
    this_object());
}
 
  if(arg) return;
 
  add_exit("north","/wizards/irmeli/area2/ruum16.c");
  set_not_out(1);

  short_desc = "Main gallery in third level";
  long_desc = "You have reached the third level. This is the main gallery of the third level.\n"+
                "The elevator shaft continues to down and you can see the bottom of it.\n"+
                "You can see a rock on the bottom of the elevator shaft.\n"; 
}
