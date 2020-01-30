inherit "room/room";
int turn_switch = 0;

reset(arg) {
  /* Assigning exits */
  add_exit("north","/wizards/gynter/area2/city2/r");
  /* setting desc */
  short_desc = "The Control Tower";
  long_desc = "This is one of the control towers. There are switches everywhere.\n"+
              "Blue, green, red and yellow. But there are one that really catches your eye.\n";

  items = allocate(2);

  items[0] = "switch";
  items[1] = "The switch is made out of a mineral unknown to you.\nYou feel like a kid again. You just wan't to turn all switches";
}

init() {
  ::init();
  add_action("turn_switch","turn");
}

turn_switch(str) {
  if(str != "switch") return;
  if(!turn_switch) {
    write("As you turn the switch you see it start to shine with\n");
    write("a blinding light. And suddenly you hear a clicking sound.\n");
    this_player()->set_quest("Therheran, Pulled Lever Two");
    turn_switch = 1;
    return 1;
  } else {
    write("You have already turned the switch.\n");
    return 1;
  }
}
