inherit "room/room";




reset(arg) {
   if(arg) return;




  add_exit("north","/wizards/siki/island/floorb8");
  add_exit("south","/wizards/siki/island/floorb10");




  short_desc = "A mining tunnel";
  long_desc = "A dark mining tunnel leading into north and south. The\n"+
              "marks on the cold stone walls are quite new. The walls\n"+
              "are secured with large wooden bars. A torch in an iron\n"+
              "handle on the wall lights the room a bit.\n";



  set_not_out(1);

  set_light(2);
  items = allocate(10);
  items[0] = "marks";
  items[1] = "Marks of mining on the walls";
  items[2] = "bar";
  items[3] = "Large wooden bar used to secure the walls of the tunnel";
  items[4] = "bars";
  items[5] = "Large wooden bars used to secure the walls of the tunnel";
  items[6] = "torch";
  items[7] = "A torch burning warmly and bringing light to the darkness";
  items[8] = "handle";
  items[9] = "An iron handle holding the torch";

}