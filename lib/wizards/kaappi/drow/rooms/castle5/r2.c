inherit "room/room";

reset(arg) {

  if(arg) return;

  add_exit("east", "r3.c");
  add_exit("north", "r5.c");

  short_desc = "A hallway";
  long_desc = "The hallway continues to the east and north.\n"+
              "A small stairs can be seen in the north. The silence\n"+
              "of this place makes you shiver. There is a huge\n"+
              "symbol on the wall. It is the same symbol thath\n"+
              "you saw outside of the castle.\n"; 
  set_light(1);
}
