inherit "room/room";

reset(arg) {

  if(arg) return;

  add_exit("west", "r3.c");
  add_exit("north", "r7.c");

  short_desc = "A hallway";
  long_desc = "The hallway continues to the west and north.\n"+
              "A small stairs can be seen in the north. The silence\n"+
              "of this place makes you shiver. There is a small and\n"+
              "empty bookshelf leaning agains the wall.\n"; 
  set_light(1);

items = allocate(2);
  items[0] = "bookshelf";
  items[1] = "Just an empty and broken bookshelf";
}
