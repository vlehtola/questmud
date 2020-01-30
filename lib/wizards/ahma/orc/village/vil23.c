inherit "room/room";
int tree_shaken, mob;

reset(arg) {
  tree_shaken = 0;
  add_exit("north", "/wizards/ahma/orc/village/vil24");
  add_exit("northwest", "/wizards/ahma/orc/village/vil09");
  add_exit("southeast", "/wizards/ahma/orc/village/vil26");
  short_desc = "Intersection between Sralk and Nuft streets";
  long_desc = "########### The Nuft street starts here and leads to north. The Sralk street\n" + 
             "#  \\ |    # continues to northwest and southeast. In southeast can be seen an\n" + 
              "#   `*,   # entrance to the thick forest. In south can be seen an apple tree\n" + 
             "#      \\  # in the backyard of a crude house. The eastern side the road is\n" + 
              "########### lined with deciduous trees. Some leaves have fallen on the street.\n";

  items = allocate(4);
  items[0] = "tree";
  items[1] = "The apple tree seems to have some ripe apples hanging from its branches.\n" + 
             "You cannot reach them, though. Maybe the good old banging would help you";
  items[2] = "leaves";
  items[3] = "Some leaves from oaks and maples are lying on the road ahead of you.\n" + 
             "The sight is not unusual, though it is not even fall yet";

  tree_shaken = 0;

  if(mob < 1) { move_object(clone_object("/wizards/ahma/orc/mob/woman"), this_object()); mob++; }
}

init() {
  ::init();
  add_action("map", "map");
  add_action("hep", "bang");
  add_action("hap", "shake");
}

map() {
  tell_object(this_player(), read_file("/wizards/ahma/orc/map"));
  return 1;
}

hep(str) {
  if(str == "tree") {
    write("You bang the apple tree hard but nothing happens. To get an apple falling you\n" + 
          "have to try something else.\n");
    say(this_player()->query_name() + " bangs apple tree hard but nothing happens.\n");
    return 1;
  }
}

hap(str) {
  if(str == "tree") {
  if(!tree_shaken) {
    write("You shake the apple tree maniacally and after a moment you manage to drop an\n" + 
          "apple on the ground.\n");
    say(this_player()->query_name() + " starts shaking the apple tree maniacally and after a while manages\n" + 
                                      "to drop an apple on the ground.\n");
    move_object(clone_object("/wizards/ahma/orc/eq/apple"), this_object());
    tree_shaken = 1;
    return 1;
  }
  else {
    write("Nothing happens. Someone must have shaken the tree a little time ago, because\n" + 
          "there does not seem to be any apples ripe enough to fall down. You will have to\n" + 
          "wait for a moment.\n");
    say(this_player()->query_name() + " shakes the tree but does not manage to drop any apples down.\n");
    return 1;
  }
  {
    write("Shake what?\n");
    return 1;
  }
}
}

childdead() {
  mob--;
}
