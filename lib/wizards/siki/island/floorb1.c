inherit "room/room";




reset(arg) {
     if(arg) return;

  add_exit("west","/wizards/siki/island/floorb2");
  add_exit("north","/wizards/siki/island/floorb4");
  add_exit("east","/wizards/siki/island/floorb6");
  add_exit("south","/wizards/siki/island/floorb5");
  add_exit("up","/wizards/siki/island/cave5");

  set_not_out(1);
  set_light(2);


  short_desc = "A mining tunnel";
  long_desc = "A huge hall with tunnels leading into every directions. \n"+
              "The walls are secured with huge wooden bars. The rusty iron\n"+
              "stairs makes it possible to go upwards. A torch in an iron\n"+
              "handle on the wall lights the room a bit. \n";

  items = allocate(10);
  items[0] = "bar";
  items[1] = "Large wooden bar used to secure the walls of the tunnel";
  items[2] = "bars";
  items[3] = "Large wooden bars used to secure the walls of the tunnel";
  items[4] = "stairs";
  items[5] = "Rusty iron stairs leading upwards";
  items[6] = "torch";
  items[7] = "A torch burning warmly and bringing light to the darkness";
  items[8] = "handle";
  items[9] = "An iron handle holding the torch";
}
