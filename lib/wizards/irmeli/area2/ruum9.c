inherit "room/room";
object monster;

reset(arg) {
  if(!present("hobbit 1")) { 
    move_object(clone_object("/wizards/irmeli/area2/hobbit2.c"),
    this_object());
}  

  if(arg) return;

  add_exit("south","/wizards/irmeli/area2/ruum10.c");
  add_exit("east","/wizards/irmeli/area2/ruum8.c");
  set_not_out(1);
  
  short_desc = "Small gallery in the second level";
  long_desc = "The deeper you go in this mine the smaller galleries get. There is a\n"+
                "skeleton of a miner who left trap in here when this gallery\n"+
                "collapsed in explonation.\n";   
  
  items = allocate(2);
  items[0] = "skeleton";
  items[1] = "A skeleton of miner who met his death at young age. Some clothes are still on it"; }


