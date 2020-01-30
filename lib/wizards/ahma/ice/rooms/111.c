inherit "room/room";
int dug;

reset(arg) {
  if(arg) return;
  add_exit("southwest", "110");
  short_desc = "An end of a tunnel";
  long_desc = "Two assembled tunnels eventually end into a sturdy-looking wall. The\n" +
              "numerous footprints pressed in the thin layer of snow in this part of the\n" +
              "tunnel indicate,that this route is quite often used. In the corner, where\n" +
              "the tunnel ends, seems to be some kind of a pile of snow. It looks like\n" +
              "tunnel's icy walls would emit a gentle, blue glow along the tunnels. The\n" +
              "ceiling seems to be full of small icicles.\n";
  items = allocate(6);
  items[0] = "footprints";
  items[1] = "Numerous fading footprints lead from southwest to somewhere near the wall.\n" +
             "The footprints show, that the movement in this part of the tunnel has been\n" +
             "very active. There are footprints going in both directions, to the wall\n" +
             "and away from it";
  items[2] = "pile";
  items[3] = "A pile of snow can be seen near the wall where the tunnel ends. It also\n" +
             "seems that the footprints on the floor end and begin near the pile. There\n" +
             "must be something special about the snow pile";
  items[4] = "snow";
  items[5] = "A pile of snow can be seen near the wall where the tunnel ends. It also\n" +
             "seems that the footprints on the floor end and begin near the pile. There\n" +
             "must be something special about the snow pile";
  if(!present("wolverine")) move_object(clone_object("/wizards/ahma/ice/mob/wolverine"), this_object());
}

init() {
  ::init();
  call_out("icedrop", 1);
  add_action("hep", "dig");
  add_action("hep", "move");
}

icedrop() {
  if(present(this_player())) call_out("icedrop", 3);
  else return 1;
  if(random(200)) return;
  tell_room(this_object(), "A sharp icicle falls down from the ceiling.\n");
  if(!random(2)) {
    tell_object(this_player(), "You grunt in pain as the icicle hits you!\n");
    say("An icicle hits " + this_player()->query_name() + "!\n");
    if(this_player()->query_name() == "Wolverine") return;
    this_player()->hit_with_spell(random(31) + 1);
  }
  else {
    tell_room(this_object(), "The icicle breaks into pieces as it lands on the ground.\n");
  }
  return 1;
}

hep(str) {
  if(str == "snow" || str == "ground" || str == "floor" || str == "pile") {
    if(dug) return;
    write("You dig the snow near the tunnel wall and reveal a hole leading down.\n");
    say(this_player()->query_name() + " digs the snow near the tunnel wall and reveals a hole leading down.\n");
    add_exit("hole", "201");
    dug = 1;
    items[3] = "A pile of snow can be seen near the wall where the tunnel ends. It also\n" +
               "seems that the footprints on the floor end and begin near the pile. Under\n" +
               "the pile seems to be a hole leading down";
    items[5] = "A pile of snow can be seen near the wall where the tunnel ends. It also\n" +
               "seems that the footprints on the floor end and begin near the pile. Under\n" +
               "the pile seems to be a hole leading down";
    return 1;
  }
  else return;
}
