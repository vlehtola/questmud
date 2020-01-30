inherit "room/room";
int moved, taken;

reset(arg) {
  if(arg) return;
  add_exit("south", "107");
  short_desc = "A dead end in narrow tunnel";
  long_desc = "The narrow, uncomfortable tunnel ends into a sturdy wall covered with\n" +
              "frozen snow. There seems to be no way of getting through the wall, which\n" +
              "makes the tunnel leading back to the south the only exit. The snow near\n" +
              "the northern wall seems to be coloured in faint red for some reason. A\n" +
              "small amount of snow has been piled against the wall in north.\n";
  items = allocate(6);
  items[0] = "snow";
  items[1] = "The snow near the northern wall is coloured in pink or faint red. Some soft\n" +
             "footprints can also be seen pressed on the ground a small distance away from\n" +
             "the wall. A small pile of snow seems to be piled against the wall in north.\n" +
             "No obvious reason is seen why the snow would be coloured";
  items[2] = "pile";
  items[3] = "A small pile of snow has been piled against the northern wall. No conclusion\n" +
             "can be made why the pile would be there. Maybe there is something hidden in it";  
  items[4] = "skull";
  items[5] = "You see nothing special";
  if(!present("husky 2")) move_object(clone_object("/wizards/ahma/ice/mob/husky"), this_object());
  if(!present("husky 2")) move_object(clone_object("/wizards/ahma/ice/mob/husky"), this_object());
  present("husky")->golden(); present("husky")->reset(0);
}

init() {
  ::init();
  add_action("hep", "move");
  add_action("hep", "dig");
  add_action("hap", "take");
  add_action("hap", "get");
}

hep(str) {
  if(str == "pile" || str == "snow") {
  if(moved) return;
  write("You dig the small pile of snow and discover a bloody skull inside it.\n");
  say(this_player()->query_name() + " digs the small pile of snow, revealing a bloody skull inside it.\n");
  items[5] = "Seems that this skull once belonged to a humanoid creature. Maybe some\n" +
             "ferocious animal living in the tunnels has been devouring the poor owner\n" +
             "of this bloody skull";
  moved = 1;
  return 1;
  }
  else { return; }
}

hap(str) {
  if(!moved) return;
  if(str != "skull") return;
  if(taken) {
    write("You don't see a skull around here.\n");
    return 1;
  }
  write("You take the bloody skull inside the pile of snow.\n");
  say(this_player()->query_name() + " takes the bloody skull inside the pile of snow.\n");
  move_object(clone_object("/wizards/ahma/ice/eq/skull"), this_player());
  taken = 1;
  reset(0);
  return 1;
}
