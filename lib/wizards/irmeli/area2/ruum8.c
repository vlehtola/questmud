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

  add_exit("west","/wizards/irmeli/area2/ruum9.c");
  add_exit("east","/wizards/irmeli/area2/ruum12.c");
  add_exit("north","/wizards/irmeli/area2/ruum7.c");
  set_not_out(1);
  
  short_desc = "Small gallery in the second level";
  long_desc = "The deeper you go in this mine the smaller galleries get. There is a small\n"+
                "punch powder on the floor. You can smell the sweat of miners who\n"+
                "worked in here.\n";   
  
  items = allocate(2);
  items[0] = "powder";
  items[1] = "A punch of wet powder. You can imagine how efficient material this was if you look this gallery"; }


