inherit "room/room";
int i = random(4);
object mob;

reset(arg) {
  add_exit("north", "312");
  add_exit("south", "307");
  add_exit("west", "309");
  add_exit("southwest", "306");
  short_desc = "On a frozen pond";
  long_desc = read_file("/wizards/ahma/ice/rooms/icedesc");

  if(!mob) {
    if(i == 0) move_object(mob = clone_object("/wizards/ahma/ice/mob/ayeti"), this_object());
    if(i == 1) move_object(mob = clone_object("/wizards/ahma/ice/mob/sgolem"), this_object());
    if(i == 2) move_object(mob = clone_object("/wizards/ahma/ice/mob/igolem"), this_object());
    if(i == 3) {
      if(random(2)) {
        move_object(mob = clone_object("/wizards/ahma/ice/mob/sgolem"), this_object());
      }
      else {
        move_object(mob = clone_object("/wizards/ahma/ice/mob/ayeti"), this_object());
      }
    }
  }
}

init() {
  ::init();
  call_out("icedrop", 1);
  add_action("north", "north");
  add_action("south", "south");
  add_action("west", "west");
  add_action("southwest", "southwest");
}

icedrop() {
  if(present(this_player())) call_out("icedrop", 3);
  else return 1;
  if(random(100)) return;
  tell_room(this_object(), "A sharp icicle falls down from the ceiling.\n");
  if(!random(2)) {
    tell_object(this_player(), "You grunt in pain as the icicle hits you!\n");
    say("An icicle hits " + this_player()->query_name() + "!\n");
    if(this_player()->query_name() == "Adult yeti" || this_player()->query_name() == "Ice golem" || this_player()->query_name() == "Snow golem") return;
    this_player()->hit_with_spell(random(51) + 1);
  }
  else {
    tell_room(this_object(), "The icicle breaks into pieces as it lands on the ground.\n");
  }
  return 1;
}

north() {
  write("You start slippering onwards on the icy surface.\n");
  call_out("moveon", (random(3) + 1), 0);
  return 1;
}

south() {
  write("You start slippering onwards on the icy surface.\n");
  call_out("moveon", (random(3) + 1), 1);
  return 1;
}

west() {
  write("You start slippering onwards on the icy surface.\n");
  call_out("moveon", (random(3) + 1), 2);
  return 1;
}

southwest() {
  write("You start slippering onwards on the icy surface.\n");
  call_out("moveon", (random(3) + 1), 3);
  return 1;
}

moveon(i) {
  if(i == 0) this_player()->move_player("north#/wizards/ahma/ice/rooms/312.c");
  if(i == 1) this_player()->move_player("south#/wizards/ahma/ice/rooms/307.c");
  if(i == 2) this_player()->move_player("west#/wizards/ahma/ice/rooms/309.c");
  if(i == 3) this_player()->move_player("southwest#/wizards/ahma/ice/rooms/306.c");
  return 1;
}