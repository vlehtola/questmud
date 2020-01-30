inherit "room/room";
inherit "room/door";
reset(arg) {

   add_exit("northwest", "hallway3.c");
   add_exit("southeast", "hallway1.c");
   short_desc = "Westside archway and a door leading to the southwest.";
   long_desc = "Wide archway leading around the tower's first floor.\n"+
               "Dozens of floating candles light the archway beautifully\n"+
               "all the five meter way to the ceiling. On the western wall\n"+
               "is a closed wooden door. Some kind of a nameplate is attached\n"+
               "on it but the letters look ancient mage symbols and you can't\n"+
               "figure what they say.\n"; 
set_light(2);

door_reset();
   set_door_label("wooden door",1);
   set_door_dir("southwest", "koppi1.c",1);
   set_door_link("/wizards/nipa/areat/torni/huoneet/koppi1.c",1);
   set_locked(0, 1);

set_not_out();
}

init() {
  ::init();
  door_init();
}
