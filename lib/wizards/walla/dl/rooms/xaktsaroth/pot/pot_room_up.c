inherit "room/room"; 
object monster;
 
reset(arg) {
  if(!present("draconian")) {
    move_object(clone_object("/wizards/walla/dl/monsters/potdrac.c"),
    this_object());
  }
 
  if(arg) return;
 
  add_exit("west","/wizards/walla/dl/rooms/xaktsaroth/pot_room_down.c");
  add_exit("pot","/wizards/walla/dl/rooms/xaktsaroth/pot/potup.c");
  set_not_out(1);
 
  short_desc = "A room with a lift";
  long_desc = "This is a room that has an immense hole in the middle, with pot sticking out of it.\n"+
              "The pot is used by the draconians to head for different levels in this underground\n"+
              "world. The pot in this room only seems to be heading upwards.\n";
 
  items = allocate(2);
  items[0] = "pot";
  items[1] = "A huge pot, with room for many people inside";
 
  call_other("wizards/walla/dl/rooms/xaktsaroth/potup.c", "start_pot", 1);
}
