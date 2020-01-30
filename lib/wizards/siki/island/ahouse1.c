inherit "room/room";

reset(arg) {

  add_exit("south","/wizards/siki/island/v_map: 15 13");
  add_exit("north","/wizards/siki/island/v_map: 15 13");
  add_exit("east","/wizards/siki/island/v_map: 15 13");
  add_exit("west","/wizards/siki/island/v_map: 15 13");
  add_exit("enter","/wizards/siki/island/ahouse2");


  short_desc = "Infront of a small house";
  long_desc = "A small wooden house with a plat roof. The walls are covered\n"+
              "with moss. There is nothing growing infront of the door, only\n"+
              "hard terrain.\n";

  items = allocate(2);
  items[0] = "door";
  items[1] = "A wooden door which is open. It seems to be stuck";
}
