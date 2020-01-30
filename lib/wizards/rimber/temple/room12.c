inherit "room/room";

reset(arg) {
 if(arg) return;
 set_light(3);
 short_desc = "Inside the temple";
  long_desc = "The basement of the temple is full of different kind of statues and potraits\n"+
                       "of the ancients who once built the city. Strange music is filling the corridor\n"+
                       "and the torches are illuminating the whole room. The priests of ancients are\n"+
                       "here to pray. This place is the largest sanctuary in the city of Asgroth.\n";
 add_exit("south", "/wizards/rimber/temple/room2.c");
}
