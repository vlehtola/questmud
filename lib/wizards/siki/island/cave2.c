inherit "room/room";


   reset(arg) {
      if(arg) return;



  add_exit("down","/wizards/siki/island/cave3");
  add_exit("up","/wizards/siki/island/cave1");


  set_not_out(1);


  short_desc = "A narrow shaft";
  long_desc = "A deep, dark shaft leading into the darkness. The walls of\n"+
              "the tunnel are secured with large wooden bars. The tunnel\n"+
              "lowers extremely sharply and you have a hard time to stand\n"+
              "still.\n";

  items = allocate(4);
  items[0] = "bar";
  items[1] = "Large wooden bar used to secure the walls of the tunnel";
  items[2] = "bars";
  items[3] = "Large wooden bars used to secure the walls of the tunnel";

}
