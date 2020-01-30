inherit "room/room";

reset(arg) {
  short_desc = "Diving in a forest pond";
  property = allocate(2);
  property[0] = "no_summon";
  property[1] = "no_spell";
  set_water(10);
}

goodlong() {
  long_desc = "The bottom and the population of different plants in the pond can be seen\n" + 
              "amazingly well when diving in it, like the bottom would be resonating some\n" + 
              "light to illuminate the whole pond.\n";
}
badlong() {
  long_desc = "The greeny water blocks your sight in every direction, and besides, it burns\n" +
              "your eyes with extreme force.\n";
}
