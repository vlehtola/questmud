inherit "room/room";
object monster;

reset(arg) {
  if(!present("hobbit 1")) { 
    move_object(clone_object("/wizards/irmeli/area2/hobbit3.c"),
    this_object());
}  

  if(arg) return;

  add_exit("north","/wizards/irmeli/area2/ruum21.c");
  add_exit("west","/wizards/irmeli/area2/ruum16.c");
  set_not_out(1);
  
  short_desc = "Hobbits dining room";
  long_desc = "This room was dining room for miners. It is bigger than regular rooms.\n"+
                "There is a big table covered with moss in the centre of room. Some\n"+
                "chairs is lying next to table.\n";   
  
  items = allocate(2);
  items[0] = "table";
  items[1] = "A big table made for 12 persons. It's covered mostly with moss"; }


