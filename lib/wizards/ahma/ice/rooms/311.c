inherit "room/room";
int taken, i, done;

reset(arg) {
  if(!present("dog", this_object())) move_object(clone_object("/wizards/ahma/ice/mob/guarddog"), this_object());
  if(arg) return;
  add_exit("south", "309");
  add_exit("east", "312");
  add_exit("southeast", "310");
  add_exit("enter", "i04");
  short_desc = "A snowy shore of a frozen pond";
  long_desc = "The icy pond ends into a small strip of snowy land. From north and west\n" +
              "the strip is bordered with sturdy and frozen-looking snowy walls. The\n" +
              "ceiling, where can be seen some icicles, is pitched towards the frozen\n" +
              "wall in north. By the northern wall, almost touching the ceiling, can\n" +
              "be seen an igloo. The doorway is blocked with a planket, but the igloo\n" +
              "can still be entered without any troubles. Near the doorway seems to be\n" +
              "a small campfire.\n";
  
  items = allocate(6);
  items[0] = "campfire";
  items[1] = "There seems to be a specific place for a campfire in here. The actual\n" +
             "campfire has already died, but there still seems to be a brass tea pan\n " +
             "hanging over the campfire";
  items[2] = "tea pan";
  items[3] = "A brass tea pan is hanging over the died campfire. It emits a weak,\n" +
             "fascinating scent, as if there would be some special liquid in it";
  items[4] = "pan";
  items[5] = "A brass tea pan is hanging over the died campfire. It emits a weak,\n" +
             "fascinating scent, as if there would be some special liquid in it";
  set_blocker("dog", "enter");
}

init() {
  ::init();
  if(present("dooris",this_object())) present("dooris",this_object())->checkroom();
  call_out("icedrop", 1);
  add_action("take", "take");
  add_action("take", "get");
  add_action("enter", "enter");
}

icedrop() {
  if(present(this_player())) call_out("icedrop", 3);
  else return 1;
  if(random(100)) return;
  tell_room(this_object(), "A sharp icicle falls down from the ceiling.\n");
  if(!random(2)) {
    tell_object(this_player(), "You grunt in pain as the icicle hits you!\n");
    say("An icicle hits " + this_player()->query_name() + "!\n");
    if(this_player()->query_name() == "Gordon" || this_player()->query_name() == "Dooris" || this_player()->query_name() == "Dog") return;
    this_player()->hit_with_spell(random(51) + 1);
  }
  else {
    tell_room(this_object(), "The icicle breaks into pieces as it lands on the ground.\n");
  }
  return 1;
}

take(str) {
  if(taken) return;
  if(str == "tea pan" || str == "pan") {
    write("You take a brass tea pan.\n");
    say(this_player()->query_name() + " takes a brass tea pan.\n");
    move_object(clone_object("/wizards/ahma/ice/eq/teapan"), this_player());
    items[1] = "There seems to be a specific place for a campfire in here. The actual\n" +
               "campfire has already died";
    items[3] = "You see nothing special";
    items[5] = "You see nothing special";
    taken = 1;
    return 1;
  }
  else return;
}

firespec() {
  items[1] = "There seems to be a specific place for a campfire in here. Some bones\n" +
             "are burning inside the area bordered by few frozen stones. The camp-\n " +
             "fire's warmth can hardly be felt";
}

specdesc() {
  long_desc = "The icy pond ends into a small strip of snowy land. From north and west\n" +
              "the strip is bordered with sturdy and frozen-looking snow walls. The\n" +
              "ceiling, where can be seen some icicles, is pitched towards the frozen\n" +
              "wall. By the northern wall, almost touching the ceiling, can be seen an\n" +
              "igloo. The doorway is blocked with a planket, but the igloo can still\n" +
              "be entered without any troubles. Near the doorway seems to be a small\n" +
              "campfire. A stange glow blocks the doorway leading into the igloo.\n";
  i = 1;
}

enter() {
  if(!i) return;
  write("The glow in the igloo's doorway prevents you from entering it!\n");
  return 1;
}

pantaken() {
  items[1] = "There seems to be a specific place for a campfire in here. The actual\n" +
             "campfire has already died";
  items[3] = "You see nothing special";
  items[5] = "You see nothing special";
}
