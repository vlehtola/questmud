inherit "room/room";
object spec;
int flowers_taken, door_open;

reset(arg) {
  items = allocate(2);
  items[0] = "flowers";
  items[1] = "Some beautiful violets are being grown in the front yard of the house";
  flowers_taken = 0;  
  
  if(arg) return;
  add_exit("south", "/wizards/ahma/orc/village/vil28");
  add_exit("west", "/wizards/ahma/orc/village/vil20");
  add_exit("southeast", "/wizards/ahma/orc/village/vil23");
  short_desc = "Intersection between Sralk and Ilem streets";
  long_desc = "########### The Sralk street continues to west and southeast and the Ilem\n" + 
              "#|   H    # street leads to south. The town square can be seen in southwest,\n" + 
              "#+---*,   # but it is surrounded by a deep moat. Two bridges are leading into\n" + 
             "#### | \\  # the square in northern and southern part of it. A red-painted house\n" + 
              "########### is located in north. Some flowers are growing in its front yard.\n" +
              "            The door leading into the red-painted house is closed.\n";
}

init() {
  ::init();
  add_action("map", "map");
  add_action("hep", "pick");
  add_action("hap", "open");
  add_action("north", "north");
}

map() {
  tell_object(this_player(), read_file("/wizards/ahma/orc/map"));
  return 1;
}

hep(str) {
  if(str == "flower" || str == "flowers" || str == "violet") {
  if(flowers_taken != 2) {
    write("You pick a violet growing in the yard of the house.\n");
    say(this_player()->query_name() + " picks a flower growing in the yard of the house.\n");
    move_object(clone_object("/wizards/ahma/orc/eq/violet"), this_player());
    flowers_taken++;
    return 1;
  }
  else {
    write("Someone else has already picked some of the violets and you do not want to\n" + 
          "ruin the whole planting by taking too much of the flowers away. You have to \n" + 
          "wait for a moment that some more violets grow up.\n");
    return 1;
  }
  {
    write("Pick what?\n");
    return 1;
  }
}
}

hap(str) {
  if(str == "door") {
  if(!door_open) {
    write("You open the door leading to the red-painted house.\n");
    say(this_player()->query_name() + " opens the door leading to the red-painted house.\n");
    door_open = 1;
    add_exit("north", "/wizards/ahma/orc/village/house07");
    long_desc = "########### The Sralk street continues to west and southeast and the Ilem\n" + 
                "#|   H    # street leads to south. The town square can be seen in southwest,\n" + 
                "#+---*,   # but it is surrounded by a deep moat. Two bridges are leading into\n" + 
               "#### | \\  # the square in northern and southern part of it. A red-painted house\n" + 
                "########### is located in north. Some flowers are growing in its front yard.\n";
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
    write("The door leading into the red-painted house is closed.\n");
    return 1;
  }
  else {
    return;
  }
}

