inherit "room/room";
int opened;
object mob;

reset(arg) {
  if(arg) return;
  short_desc = "In a small wooden cottage";
  long_desc = "The cottage looks much bigger inside than from outside. The outlook of\n" +
              "the cottage is very official. The workdesk by the northern wall is facing\n" +
              "towards the door, which is in the opposite wall of the room than the desk.\n" +
              "On the floor lies a greenish carpet, which reaches all the way from the\n" +
              "door to the desk. On the walls there are hanging some paintings and a\n" +
              "proud-looking, big moose head. A small window is located in the wall behind\n" +
              "the desk.\n";

  items = allocate(14);
  items[0] = "door";
  items[1] = "A simple wooden door. There seems to be no lock on it, so it can be\n" + 
             "opened and closed whenever needed. The door is closed";
  items[2] = "desk";
  items[3] = "Quite large, wooden workdesk is standing in the northern end of the room.\n" + 
             "The desk is facing towards the door and it looks very official. The desk\n" + 
             "alone lays the office-like atmosphere over this cottage";
  items[4] = "carpet";
  items[5] = "Ordinary-looking light green carpet is covering the floor all the way\n" + 
             "from door to workdesk. The carpet is quite thin and it does not soften\n" + 
             "the floor almost at all. Seems that it lies on the floor only for its\n" + 
             "outlook, not for the comfortability";
  items[6] = "painting";
  items[7] = "Try looking at 'paintings'";
  items[8] = "head";
  items[9] = "A proud and quite big moose head is hanging on the wall over the door\n" + 
             "leading to this cottage. The moose has big horns which indicate that\n" + 
             "it is a male. Supposedly the moose has been hunt down from somewhere\n" + 
             "in the forest surrounding the cottage";
 items[10] = "window";
 items[11] = "A small window is located in the wall behind the workdesk. Some light\n" + 
             "is shining in from the window, though it gives out to the green forest.\n" + 
             "Nothing out of ordinary can be seen in the forest";
 items[12] = "paintings";
 items[13] = "Some family pictures has been hung on the wall. Most likely the paintings\n" +
             "belong to the owner of this cottage. In all of the paintings there seems\n" +
             "to be pictured three children and two adults. They all look very happy in\n" +
             "every painting";

  if(opened) { door_open(); } else { door_closed(); }
  if(!mob) { move_object(mob = clone_object("/wizards/ahma/orc/mob/hans"), this_object()); }
}

init() {
  ::init();
  add_action("door1", "open");
  add_action("door2", "close");
}

door1(str) {
  if(str == "door") {
  if(!opened) {
    write("You open the wooden door leading out of the cottage.\n");
    say(this_player()->query_name() + " opens a wooden door leading out of the cottage.\n");
    add_exit("out", "/wizards/ahma/orc/forest/for15");
    call_other("/wizards/ahma/orc/forest/for15", "add_exit", "enter", "/wizards/ahma/orc/forest/house01");
    call_other("/wizards/ahma/orc/forest/for15", "door_open");
    tell_room("/wizards/ahma/orc/forest/for15", "The door leading into the cottage opens.\n");
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
    write("You close the wooden door leading out of the cottage.\n");
    say(this_player()->query_name() + " closes the door leading out of the wooden cottage.\n");
    remove_exit("out");
    call_other("/wizards/ahma/orc/forest/for15", "remove_exit", "enter");
    call_other("/wizards/ahma/orc/forest/for15", "door_closed");
    tell_room("/wizards/ahma/orc/forest/for15", "The door leading into the cottage closes.\n");
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
  items[1] = "A simple wooden door. There seems to be no lock on it, so it can be\n" + 
             "opened and closed whenever needed. The door is closed";
  return 1; 
}

door_open() {
  opened = 1;
  items[1] = "A simple wooden door. There seems to be no lock on it, so it can be\n" + 
             "opened and closed whenever needed. The door is open";
  return 1; 
}
