inherit "room/room";
object monster01, monster02;
int door_open;

reset(arg) {
  add_exit("west", "/wizards/ahma/orc/village/vil21");
  add_exit("southeast", "/wizards/ahma/orc/village/vil24");
  short_desc = "Central part of Nuft street";
  long_desc = "########### The Nuft street continues to west and southeast. In northwest can\n" + 
              "#|        # be seen an entrance to deeper inside the forest. In east stands\n" + 
              "#+---*,-H # somewhat bigger and more maintained house than others in the\n" + 
             "#|     \\  # village. The house is made of grey stones. There seems to be some\n" + 
              "########### kind of a sign hanging on the wall next to the door.\n";

  items = allocate(2);
  items[0] = "sign";
  items[1] = "You want to move into our village? Well I don't care! Contact my trusted\n" + 
             "attendant Hans if you have something to discuss about. He is living somewhere\n" + 
             "in the woods. Yes, I think he's a bit insane, too. Now scram!\n" + 
             "- Sincerely in your service, Village Chief Tas'gand";

  if(!monster01) { move_object(monster01 = clone_object("/wizards/ahma/orc/mob/guard"), this_object()); }
  if(!monster02) { move_object(monster02 = clone_object("/wizards/ahma/orc/mob/guard"), this_object()); }
}

init() {
  ::init();
  add_action("map", "map");
  add_action("hep", "open");
  add_action("east", "east");
}

map() {
  tell_object(this_player(), read_file("/wizards/ahma/orc/map"));
  return 1;
}

hep(str) {
  if(str == "door") {
  if(!door_open) {
    write("You open the door leading into the chief's house.\n");
    say(this_player()->query_name() + " opens the door leading into the chief's house.\n");
    door_open = 1;
    add_exit("east", "/wizards/ahma/orc/village/house08");
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

poppi() {
  if(!monster01) { move_object(clone_object("/wizards/ahma/orc/mob/guard"), this_object()); }
  if(!monster02) { move_object(clone_object("/wizards/ahma/orc/mob/guard"), this_object()); }
}

east() {
  if(!door_open) {
    write("The door leading into the chief's house is closed.\n");
    return 1;
  }
  else {
    return;
  }
}
