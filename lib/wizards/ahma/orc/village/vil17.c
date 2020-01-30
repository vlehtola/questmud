inherit "room/room";
int mob;

reset(arg) {
  add_exit("east", "/wizards/ahma/orc/village/vil21");
  add_exit("southwest", "/wizards/ahma/orc/village/vil16");
  short_desc = "Central part of Nuft street";
  long_desc = "########### The Nuft street continues to east and southwest. In northeast seems\n" + 
              "#        |# to be an entrance leading deeper in the forest surrounding this\n" + 
              "#   ,*---+# small village. The road is lined with bushes and trees, which block\n" + 
              "#  /     |# the view to anywhere else but forward and backward on the road.\n" + 
              "########### Some birds are singing on the branches of a nearby tree.\n";

  items = allocate(2);
  items[0] = "birds";
  items[1] = "You find it very difficult to believe your eyes when you see what kind of\n" +
             "birds are sitting on the branches of a nearby oak. They are nightingales,\n" +
             "and it seems that there are at least five or six of them. Very unusual sight,\n" +
             "but you like it";

  if(mob < 1) { move_object(clone_object("/wizards/ahma/orc/mob/child"), this_object()); mob++; }
}

init() {
  ::init();
  add_action("map", "map");
}

map() {
  tell_object(this_player(), read_file("/wizards/ahma/orc/map"));
  return 1;
}

childdead() {
  mob--;
}