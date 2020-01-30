inherit "room/room";
int taken, moved;

reset(arg) {
  if(!present("baby 2")) move_object(clone_object("/wizards/ahma/ice/mob/bbear"), this_object());
  if(!present("baby 2")) move_object(clone_object("/wizards/ahma/ice/mob/bbear"), this_object());
  if(!present("adult")) move_object(clone_object("/wizards/ahma/ice/mob/abear"), this_object());
  if(arg) return;
  
  add_exit("out", "304");
  short_desc = "A polar bears' nest";
  long_desc = "Some polar bears have made this spacious cave in the sturdy bedrock their\n" +
              "nest. Cave's walls are thoroughly covered with frozen snow, also the ground\n" +
              "and ceiling are covered with cold, white snow. The cave is very dimly lit,\n" +
              "the only light entering the room is coming from the entrance to this cave.\n" +
              "A bloody, half-eaten corpse can be seen by the southeastern wall. The snow\n" +
              "on the ground is hardened by many paws of the bear-family living in this\n" +
              "cave.\n";

  items = allocate(4);
  items[0] = "corpse";
  items[1] = "A half-eaten corpse of some animal. Obviously, this was the bears' last\n" +
             "meal. Few bones are lying on the ground next to the corpse";
  items[2] = "bones";
  items[3] = "A pile of bit grayish bones is located near the bloody area, where the\n" +
             "corpse is lying. All the flesh has been eaten away from the bones,\n" +
             "making them to look almost shiny. Seems that these bones could even be\n" +
             "used as a firewood";
}

init() {
  ::init();
  add_action("take", "take");
  add_action("hep", "move");
}

take(str) {
  if(str == "corpse" && !present("corpse", this_object())) {
    write("You don't feel like taking the bloody corpse, but maybe you could move it.\n");
    return;
  }
  if(str != "bones") return;
  if(!taken) {
    write("You take a pile of gray bones from the ground.\n");
move_object(clone_object("/wizards/ahma/ice/eq/bones"), this_player());
    say(this_player()->query_name() + " takes a pile of gray bones from the ground.\n");
    items[1] = "A half-eaten corpse of some animal. Obviously, this was the bears' last meal";
    items[3] = "You see nothing special";
    taken = 1;
    return 1;
  }
  else return;
}

hep(str) {
  if(str != "corpse") return;
  if(present("corpse", this_object())) {
    write("You don't know which corpse to move. Get rid of the other first.\n");
    return 1;
  }
  if(!moved) {
    write("You move the bloody corpse a bit and discover a hole under it.\n");
    say(this_player()->query_name() + " moves a bloody corpse a bit and discovers a hole under it.\n");
    "/wizards/ahma/ice/rooms/secret01"->corpsemoved();
    corpsemoved();
    moved = 1;
    return 1;
  }
  else {
    write("You move the bloody corpse back to its original position, hiding the hole.\n");
    say(this_player()->query_name() + " moves the bloody corpse back to its original position, hiding the hole.\n");
    remove_exit("hole");
    "/wizards/ahma/ice/rooms/secret01"->corpsenotmoved();
    set_blocker("bear", "asdf");
    moved = 0;
    return 1;
  }
}

corpsemoved() {
  add_exit("hole", "secret01");
  set_blocker("bear", "hole");
  moved = 1;
  return 1;
}
