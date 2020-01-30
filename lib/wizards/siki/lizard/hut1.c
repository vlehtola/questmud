inherit "room/room";


reset(arg) {



  add_exit("east","/wizards/siki/lizard/hut2");
  add_exit("out","/wizards/siki/lizard/room3");


  short_desc = "A tiny straw hut";
  long_desc = "The walls are made of dry and thin straws. The ground is cold\n"+
              "and wet and there are some dead straws here and there. The room\n"+
              "is quite high and the roof is made out of some kind of leather.\n";
              
set_not_out(1);
}

