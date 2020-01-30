inherit "room/room";
int door_open, mob;

reset(arg) {
  if(mob < 1) { move_object(clone_object("/wizards/ahma/orc/mob/dog"), this_object()); mob++; }
  if(arg) return;
  add_exit("east", "/wizards/ahma/orc/village/vil12");
  add_exit("northwest", "/wizards/ahma/orc/village/vil14");
  short_desc = "Western part of Galor street";
  long_desc = "########### The Galor street continues to east and northwest. In northwest\n" + 
             "#  \\ H  | # seems to be an entrance to deeper into the forest surrounding this\n" + 
              "#   `*--+-# village. In north is located a small house with a chimney on its\n" + 
              "#       | # roof. Some steam is rising from it. A slim deer can be seen having\n" + 
              "########### a dinner with some berries behind the bushes in southwest.\n" +
              "            The door leading into the house is closed.\n";

  items = allocate(2);
  items[0] = "deer";
  items[1] = "A slim and agile-looking deer is having a dinner with a green bush. The\n" +
             "deer does not seem to be disturbed by your presence due to the thick wall\n" +
             "of tree trunks, which separate you from it";
}

init() {
  ::init();
  add_action("map", "map");
  add_action("hap", "open");
  add_action("north", "north");
}

map() {
  tell_object(this_player(), read_file("/wizards/ahma/orc/map"));
  return 1;
}

hap(str) {
  if(str == "door") {
  if(!door_open) {
    write("You open the door leading to the hut with a chimney.\n");
    say(this_player()->query_name() + " opens the door leading to the hut with a chimney.\n");
    door_open = 1;
    add_exit("north", "/wizards/ahma/orc/village/house04");
    long_desc = "########### The Galor street continues to east and northwest. In northwest\n" + 
               "#  \\ H  | # seems to be an entrance to deeper into the forest surrounding this\n" + 
                "#   `*--+-# village. In north is located a small house with a chimney on its\n" + 
                "#       | # roof. Some steam is rising from it. A slim deer can be seen having\n" + 
                "########### a dinner with some berries behind the bushes in southwest.\n";
    return 1;
  }
  else {
    write("The door is already open.\n");
    return 1;
  }
  {
    write("Open what?\n");
    return 1;
  }
}
}

north() {
  if(!door_open) {
    write("The door leading to the house with a chimney is closed.\n");
    return 1;
  }
  else {
  return;
  }
}

childdead() {
  mob--;
}