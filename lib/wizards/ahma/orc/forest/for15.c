inherit "room/room";
int opened;

reset(arg) {
  if(arg) return;
  add_exit("south", "/wizards/ahma/orc/forest/for14");
  add_exit("east", "/wizards/ahma/orc/forest/for13");
  add_exit("southeast", "/wizards/ahma/orc/forest/for12");
  short_desc = "On a small opening";
  long_desc = "The green, grassy opening is full of life. Animals wander near the\n" + 
              "edges of the opening, looking for food and ready to run into the forest\n" + 
              "if something would threaten them. The flowers sway a bit in the gentle\n" + 
              "breezes of wind, resonating the life force within them. Birds sing their\n" + 
              "songs on the brances of trees on the edge of the meadow. A crude-looking\n" + 
              "wooden cottage is standing near the edge of the forest. A sign has been\n" + 
              "nailed next to the wooden door.\n";

  items = allocate(10);
  items[0] = "flowers";
  items[1] = "Commonly seen flowers like dandelions are growing here. You do not\n" + 
             "want to examine them more than a glance because you really do see\n" + 
             "them everywhere when moving around";
  items[2] = "animals";
  items[3] = "Few wild forest animals are wandering around the opening. Maybe they\n" + 
             "are looking something to eat. The animals are aware of your presence\n" + 
             "so it would be a waste of time trying to catch or kill them";
  items[4] = "cottage";
  items[5] = "A cottage made of wood is standing in the edge of the meadow. Seems\n" + 
             "that the cottage is quite old with its decaying logs forming the walls.\n" + 
             "There seems to be a wooden sign hanging on the wall near the door\n" + 
             "leading into the cottage. The door is closed";
  items[6] = "door";
  items[7] = "A simple wooden door. There seems to be no lock on it, so it can be\n" + 
             "opened and closed whenever needed. The door is closed";
  items[8] = "sign";
  items[9] = "'Hans Barakk, the attendant of Chief Tas'gand'\n" + 
             "The carving is very patiently made and looks nice";

  if(opened) { door_open(); } else { door_closed(); }
}

init() {
  ::init();
  add_action("hep", "pick");
  add_action("door1", "open");
  add_action("door2", "close");
  if(!random(250)) {
    tell_room(this_object(), "An Orcish ranger jumps out from the bush.\n");
    move_object(clone_object("/wizards/ahma/orc/mob/ranger"), this_object());
  }
}



hep(str) {
  if(str == "flowers" || str == "dandelions") {
    write("You do not want to pick that common flowers like dandelions right now.\n");
    return 1;
  }
  else {
    return;
  }
}

door1(str) {
  if(str == "door") {
  if(!opened) {
    write("You open the wooden door leading into the cottage.\n");
    say(this_player()->query_name() + " opens a wooden door leading into the cottage.\n");
    add_exit("enter", "/wizards/ahma/orc/forest/house01");
    call_other("/wizards/ahma/orc/forest/house01", "add_exit", "out", "/wizards/ahma/orc/forest/for15");
    call_other("/wizards/ahma/orc/forest/house01", "door_open");
    tell_room("/wizards/ahma/orc/forest/house01", "The door leading out of the cottage opens.\n");
    door_open();
    return 1;
  }
  else {
    write("The door is already open.\n");
    return 1;
  }
  }
  else {
    write("Open what?\n");
    return 1;
  }
}

door2(str) {
  if(str == "door") {
  if(opened) {
    write("You close the wooden door leading into the cottage.\n");
    say(this_player()->query_name() + " closes the door leading into the wooden cottage.\n");
    remove_exit("enter");
    call_other("/wizards/ahma/orc/forest/house01", "remove_exit", "out");
    call_other("/wizards/ahma/orc/forest/house01", "door_closed");
    tell_room("/wizards/ahma/orc/forest/house01", "The door leading out of the cottage closes.\n");
    door_closed();
    return 1;
  }
  else {
    write("The door is already closed.\n");
    return 1;
  }
  }
  else {
    write("Close what?\n");
    return 1;
  }
}

door_closed() {
  opened = 0;
  items[5] = "A cottage made of wood is standing in the edge of the meadow. Seems\n" + 
             "that the cottage is quite old with its decaying logs forming the walls.\n" + 
             "There seems to be a wooden sign hanging on the wall near the door\n" + 
             "leading into the cottage. The door is closed";
  items[7] = "A simple wooden door. There seems to be no lock on it, so it can be\n" + 
             "opened and closed whenever needed. The door is closed";
  return 1; 
}

door_open() {
  opened = 1;
  items[5] = "A cottage made of wood is standing in the edge of the meadow. Seems\n" + 
             "that the cottage is quite old with its decaying logs forming the walls.\n" + 
             "There seems to be a wooden sign hanging on the wall near the door\n" + 
             "leading into the cottage. The door is open";
  items[7] = "A simple wooden door. There seems to be no lock on it, so it can be\n" + 
             "opened and closed whenever needed. The door is open";
  return 1; 
}
