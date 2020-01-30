inherit "room/room";

reset(arg) {

  if(arg) return;

  add_exit("south", "r1.c");
  add_exit("west", "r2.c");
  add_exit("east", "r4.c");
  add_exit("north", "r6.c");

  short_desc = "A hallway";
  long_desc = "The hallway continues to the east, west and north.\n"+
              "A small stairs can be seen in the north. The silence\n"+
              "of this place makes you shiver. A couple of small\n"+
              "benches is placed next to wall.\n";
 
  set_light(1);
}
