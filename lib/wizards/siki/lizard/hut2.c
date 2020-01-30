inherit "room/room";


reset(arg) {



  add_exit("west","/wizards/siki/lizard/hut1");
  add_exit("south","/wizards/siki/lizard/hut3");


  short_desc = "A tiny straw hut";
  long_desc = "The walls are made of dry and thin straws. The ground is cold\n"+
              "and wet and there are some dead straws here and there. The room\n"+
              "is quite high and the roof is made out of some kind of leather.\n";
              
set_not_out(1);
}


