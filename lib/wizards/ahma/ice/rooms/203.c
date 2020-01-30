inherit "room/room";

reset(arg) {
  add_exit("north", "202");
  add_exit("west", "206");
  add_exit("northwest", "205");
  add_exit("southeast", "204");
  short_desc = "A large opening full of icicles";
  long_desc = "You are standing in a huge opening. The ceiling is at least in the height\n" +
              "of thirteen feet. The ground is almost fully frozen, though some piles of\n" +
              "soft snow can be seen here and there. The opening continues to west- and\n" +
              "northwards. A narrow tunnel leads to southeast. The ceiling of the cavern\n" +
              "is full of sharp icicles and in the ceiling there seems to be a hole, from\n" +
              "where some light is entering into this, otherwise, dim opening. Some blood-\n" +
              "stains can be seen in the middle of the room.\n";
  items = allocate(4);
  items[0] = "blood";
  items[1] = "Bloodstains on the ground indicate about a furious battle fought. Maybe\n" +
             "some animals have fought in this very place earlier. No corpse is in\n" +
             "sight. Faint drops of blood lead to west";
  items[2] = "bloodstains";
  items[3] = "Bloodstains on the ground indicate about a furious battle fought. Maybe\n" +
             "some animals have fought in this very place earlier. No corpse is in\n" +
             "sight. Faint drops of blood lead to west";
}

init() {
  ::init();
  call_out("icedrop", 1);
}

icedrop() {
  if(present(this_player())) call_out("icedrop", 3);
  else return 1;
  if(random(180)) return;
  tell_room(this_object(), "A sharp icicle falls down from the ceiling.\n");
  if(!random(2)) {
    tell_object(this_player(), "You grunt in pain as the icicle hits you!\n");
    say("An icicle hits " + this_player()->query_name() + "!\n");
    this_player()->hit_with_spell(random(38) + 1);
    
  }
  else {
    tell_room(this_object(), "The icicle breaks into pieces as it lands on the ground.\n");
  }
  return 1;
}