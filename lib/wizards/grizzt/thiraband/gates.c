inherit "room/room";

reset(arg) {
        if(arg) return;

  add_exit("north","/wizards/grizzt/thiraband/innergates");
  add_exit("out","/wizards/grizzt/workroom");

  
  short_desc = "Next to a huge gate";
  long_desc = "The gate to the fortified city of Thiraband is right ahead. \n"+
              "Occasional visitors are walking in and out from the city.\n"+
              "The paved road seems to be wide enough for two carts to pass \n"+
              "each others.\n";


  items = allocate(4);
  items[0] = "gates";
  items[1] = "The gates look very sturdy";
  items[2] = "visitors";
  items[3] = "The visitors seem to be almost every corner of the world.";
  
        set_sound(35+random(7),"Someone bumps into you.\n");
        set_sound(40+random(3),"The guards are looking at the visitors.\n");
  

}