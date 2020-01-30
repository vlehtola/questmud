inherit "room/room";

reset(arg) {
  add_exit("north","/world/city/ice5");
  add_exit("west","/wizards/onarion/arena_west");
  add_exit("east","/wizards/onarion/arena_east");

  short_desc = "Arena entrance";
  long_desc = "You are in the arena entrance. There area some decorative\n"+
	      "weapons hanging on the wall. There is a sign on the wall.\n";

  items = allocate(2);
  items[0] = "sign";
  items[1] = "To enter the arena, type ";

  property = allocate(4);
  property[0] = "no_kill";
  property[1] = "no_skill";
  property[2] = "no_spell";
  property[3] = "no_summon";
}

init() {
  ::init();
  add_action("yeah", "yeah");
}

yeah(str) {
  if(str == "this rocks") {
    write("It sure does.\n"); /* the "\n" changes the line :) */
    return 1; /* stop the execution */
  }
  write("Blaah.\n");
  return 1;
}

