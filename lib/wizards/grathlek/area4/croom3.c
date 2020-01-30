inherit "room/room";
object monster;
 
reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/grathlek/area4/monsies/nimp.c");
    move_object(monster, this_object());
   }
  add_exit("west","/wizards/grathlek/area4/croom4.c");
  add_exit("east","/wizards/grathlek/area4/croom2.c");
  set_light(2);
 
  short_desc = "A stony park.";
  long_desc = "This is the noble area where\n"+
              "some nobles are used to discuss\n"+
              "some serious matters. A row tier\n"+
              "is here waiting for the nobles.\n";

  items = allocate(4);
    items[0] = "row";
    items[1] = "These are for the nobles.";
}
