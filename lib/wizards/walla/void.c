inherit "room/room";

  reset(arg) {

  short_desc = "Testing Grounds";
"Area 51, the testing grounds for wallas coding.\n" +
"you have no business here.\n" +
"You can see a huge crater on the ground, thanks to Walla's failed\n" +
"experiments.  \n" +
"now get lost.\n";

  property = allocate(1);
  property[0] = "no_summon";
}
