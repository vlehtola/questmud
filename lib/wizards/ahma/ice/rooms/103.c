inherit "room/room";
int hacked;

reset(arg) {
  add_exit("west", "102");
  short_desc = "A dead end";
  long_desc = "The tunnel is very squat. Its height is of a normal-sized Giant, but no\n" +
              "higher. Tunnel ends into a vertical wall, which is fully covered with\n" +
              "frozen snow. Some markings can be seen written on the wall in east. No\n" +
              "icicles can be seen in this part of the low tunnel. A snowy opening can\n" +
              "be seen in a little distance to west.\n";
  items = allocate(2);
  items[0] = "wall";
  if(!hacked) { nothacked(); } else { hacked(); }
}

nothacked() {
  items[1] = "Some markings seem to be written on the wall under the frozen layer of snow,\n" +
             "but you cannot read it clearly because all the snow on it. Maybe you could\n" +
             "somehow clear the snow off the wall";
}

hacked() {
  items[1] = "On the wall has been written with dark red, maybe blood:\n" +
             "'Welcome to the frozen tunnels of Kohr!\n" +
             "The tunnels are home of many animals and few Dwarves peacefully living\n" +
             "amongst them. Please, feel free to visit all of us, but do not cause any\n" +
             "trouble in our peaceful tunnels.'\n" +
             "- Terran, the overseer of tunnels of Kohr";
}

init() {
  ::init();
  add_action("hep", "dig");
  add_action("hep", "hack");
  add_action("hep", "hit");
  add_action("hep", "clear");
}

hep(str) {
  if(str == "wall" || str == "snow" || str == "ice") {
    if(hacked) { write("The snow has already been hacked off from the wall.\n"); return 1; }
    write("You hack the frozen snow away and discover some markings written\n" +
          "on the wall under it.\n");
    say(this_player()->query_name() + " hacks the frozen snow away and discovers some markings\n" +
        "written on the wall under it.\n");
    hacked = 1;
    hacked();
    return 1;
  }
  else return;
}
