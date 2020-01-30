inherit "room/room";
int mob;

reset(arg) {
  add_exit("north", "/wizards/ahma/orc/village/vil16");
  add_exit("northeast", "/wizards/ahma/orc/village/vil18");
  add_exit("southwest", "/wizards/ahma/orc/village/vil14");
  short_desc = "Intersection between Sralk and Nuft streets";
  long_desc = "########### The Nuft street starts here and leads to north. The Sralk\n" + 
              "#    | /  # street continues to southwest and northeast. Discarted wagons\n" + 
              "#   ,*'   # are lying in the western side of the road among the green bushes\n" + 
              "#  /      # and trees. A small hedgehog is sniffing some carbage near the\n" + 
              "########### wooden sign which is standing on the eastern side of the road.\n";

  items = allocate(8);
  items[0] = "wagons";
  items[1] = "Old and clumsy-looking wagons have been discarted in the roadside. The\n" + 
             "wagons seem to be otherwise in good condition, except some holes in the\n" + 
             "sheet covering the space where the equipment is stored. Maybe you could\n" + 
             "check what is inside the wagon by entering it";
  items[2] = "garbage";
  items[3] = "Various trash thrown away from the houses along this road";
  items[4] = "sign";
  items[5] = "'Take the outer route (Nuft) to reach Chief Tas'gand's hut. The inner route\n" +
             "(Sralk) leads to village square and other central parts of the village'";
  items[6] = "hedgehog";
  items[7] = "This small and spiky animal is trying to find some food from the garbage\n" + 
             "pile. Maybe it is finding the food for itself, or maybe, who knows, for its\n" +
             "offspring";

  if(mob < 1) { move_object(clone_object("/wizards/ahma/orc/mob/child"), this_object()); mob++; }
}

init() {
  ::init();
  add_action("map", "map");
  add_action("hep", "enter");
}

map() {
  tell_object(this_player(), read_file("/wizards/ahma/orc/map"));
  return 1;
}

hep(str) {
  if(str == "wagon" || str == "wagons") {
  write("You still try to figure out why this kind of wagons are found in this village\n" + 
        "as you enter the dark hole leading inside the cart.\n\n");
  this_player()->move_player("wagons#/wizards/ahma/orc/village/wagons.c");
  return 1;
  }
  else {
    return;
  }
}

childdead() {
  mob--;
}