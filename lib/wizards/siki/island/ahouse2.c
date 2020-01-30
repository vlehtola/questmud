inherit "room/room";


   reset(arg) {
      if(arg) return;


  add_exit("south","/wizards/siki/island/ahouse3");
  add_exit("west","/wizards/siki/island/ahouse4");
  add_exit("out","/wizards/siki/island/ahouse1");



  short_desc = "A wooden house";
  long_desc = "A small and cozy house made out of thick treetrunks. There is\n"+
              "no floor, only hard terrain covered with rabbit furs. The wooden\n"+
              "door is open.\n";
         
  items = allocate(4);
  items[0] = "furs";
  items[1] = "Nice looking rabbit furs covering the ground";
  items[2] = "door";
  items[3] = "A wooden door. It seems to be stuck";

  set_not_out(1);

}
