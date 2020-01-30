inherit "room/room";
object mob;

reset(arg) {
  add_exit("north", "306");
  add_exit("south", "302");
  add_exit("east", "304");
  short_desc = "A huge underground opening";
  long_desc = "The snow is very soft around this part of the caverns, making your feet\n" +
              "easily sink through its surface. The ceiling of this small opening is\n" +
              "about twelve feet high and covered with icicles. A huge hollow space in\n" +
              "the bedrock opens before you in north. The hall-like opening's ground is\n" +
              "covered by a frozen pond. A small snowy hill pitches down in north. In\n" +
              "south starts a smaller tunnel. In east can be seen a big promontory\n" +
              "reaching over the frotzen pond in south. Numerous small footprints are\n" +
              "leading eastwards.\n";
  if(!mob) {
  if(random(2)) {
    move_object(mob = clone_object("/wizards/ahma/ice/mob/bbear"), this_object());
    move_object(mob = clone_object("/wizards/ahma/ice/mob/bbear"), this_object());
  }
  else {
    move_object(mob = clone_object("/wizards/ahma/ice/mob/ayeti"), this_object());
  }
}
}

init() {
  ::init();
  add_action("south", "south");
  call_out("icedrop", 1);
}

icedrop() {
  if(present(this_player())) call_out("icedrop", 3);
  else return 1;
  if(random(120)) return;
  tell_room(this_object(), "A sharp icicle falls down from the ceiling.\n");
  if(!random(2)) {
    tell_object(this_player(), "You grunt in pain as the icicle hits you!\n");
    say("An icicle hits " + this_player()->query_name() + "!\n");
    if(this_player()->query_name() == "Bear" || this_player()->query_name() == "Adult yeti") return;
    this_player()->hit_with_spell(random(47) + 1);
  }
  else {
    tell_room(this_object(), "The icicle breaks into pieces as it lands on the ground.\n");
  }
  return 1;
}

south() {
  write("You start crawling in the narrow tunnel.\n");
  call_out("moveon", (random(3) + 1), 0);
  return 1;
}

moveon(i) {
  if(i == 0) this_player()->move_player("south#/wizards/ahma/ice/rooms/302.c");
  return 1;
}