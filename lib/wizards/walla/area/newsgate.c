inherit "room/room";
 
reset(arg) {
 
  add_exit("south","out: 83 55");
  short_desc = "In front of a drawbridge";
  long_desc =
"You are standing in front of a drawbridge, that leads into the city of\n" +
"Jericho. The drawbridge and the walls surrounding the city have\n" +
"been built to prevent unwanted enemies from entering the city.\n" +
"The drawbridge has been raised, and you can see a moat, covered with\n" +
"spikes and thorns, preventing you from going further.\n";
 
  items = allocate(4);
  items[0] = "moat";
  items[1] = "A moat, with spikes at the bottom";
  items[2] = "drawbridge";
  items[3] = "the drawbridge has been raised up.";
  property = allocate(4);
  property[0] = "no_kill";
  property[1] = "no_skill";
  property[2] = "no_spell";
  property[3] = "no_summon";
 
}
