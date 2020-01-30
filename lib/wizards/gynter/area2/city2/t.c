inherit "room/room";
int turned = 0;

reset(arg) {
  /* Assigning exits */
  add_exit("north","/wizards/gynter/area2/city2/q");
  /* setting desc */
  short_desc = "The Control Tower";
  long_desc = "This is the control tower. There are switches lining the walls\n"+
              "but there is only one switch of interest to you.\n";

  items = allocate(2);

  items[0] = "switch";
  items[1] = "You feel like a warrior's kid in a weapons shop.\nJust wan't to touch and turn everything";
}

init() {
  ::init();
  add_action("turn","turn");
}

turn(str) {
  if(str != "switch") return;
    if(!turned) {
      write("As you turn the switch you see it start to shine with\n");
      write("a blinding light. And suddenly you hear a clicking sound.\n");
      this_player()->set_quest("Therheran, Pulled Lever One");
      turned = 1;
      return 1;
    } else {
      write("You have already turned the switch.\n");
      return 1;
    }
}
