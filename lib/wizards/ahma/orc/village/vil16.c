inherit "room/room";
int tree_shaken;

reset(arg) {
  add_exit("south", "/wizards/ahma/orc/village/vil15");
  add_exit("northeast", "/wizards/ahma/orc/village/vil17");
  short_desc = "Western part of Nuft street";
  long_desc = "########### The Nuft street leads to south and northeast.\n" + 
              "#      /  # The deep forest is surrounding the street from its western and\n" + 
              "#    *'   # northern sides. Some animals can be heard moving in the other\n" + 
              "#    |    # side of the green and brown coloured wooden wall. Some leaves\n" + 
              "########### have fallen on the road like someone had shaken the trees.\n";
}

init() {
  ::init();
  add_action("map", "map");
  add_action("hep", "shake");
}

map() {
  tell_object(this_player(), read_file("/wizards/ahma/orc/map"));
  return 1;
}

hep(str) {
  if(str == "tree" || str == "trees") {
  if(!tree_shaken) {
    write("You start shaking the tree almost maniacally. After a moment something falls\n" + 
          "down from the tree behind your back with a loud thump. You quickly turn around\n" + 
          "to see what you managed to drop down from the tree.\n");
    say(this_player()->query_name() + " shakes one of the trees and after a moment something falls on the\n" + 
                                      "ground.\n");
    move_object(clone_object("/wizards/ahma/orc/mob/treeboy"), this_object());
    present("boy", this_object())->setplr(this_player());
    tree_shaken = 1;
    return 1;
  }
  else {
    write("You shake the tree for a moment but nothing happens and you decide to give up.\n");
    say(this_player()->query_name() + " shakes one of the trees for a moment but nothing happens.\n");
    return 1;
  }
  {
    write("Shake what?\n");
    return 1;
  }
}
}
