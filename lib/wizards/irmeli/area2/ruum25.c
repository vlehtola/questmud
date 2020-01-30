inherit "room/room";
object monster;

reset(arg) {
  if(!present("hobbit 1")) { 
    move_object(clone_object("/wizards/irmeli/area2/hobbit6.c"),
    this_object());
}  

  if(arg) return;

  add_exit("west","/wizards/irmeli/area2/ruum23.c");
  set_not_out(1);
  
  short_desc = "Bedroom for miners";
  long_desc = "This is a huge bedroom for miners. Here is about twenty beds around the\n"+
                "place. The air is stuffy and cold. There is also a big fireplace\n"+
                "to warm up miners.\n";   
  
  items = allocate(4);
  items[0] = "bed";
  items[1] = "This bed like every bed in here is made from steel. It is similar like humans beds"; 
  items[2] = "fireplace";
  items[3] = "Fireplace has just burned-out. The cold air is taking place in this room"; }

