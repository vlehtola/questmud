inherit "room/room";

reset(arg) {
        add_exit("down","tower2");
short_desc = "Hall in the tower";
long_desc = "You are standing in a hall, where the kings from other realm's meet time\n"+
            "to time. The hall is snug and elegant, furnished with carpets, paintings,\n"+
            "chairs, tables and mirrors. A perfect room for representing the kingdom.\n"+
            "The kings make important decisions about wars and peaces, in this very room.\n";
    items = allocate(4);
    items[0] = "mirror";
    items[1] = "When looking this mirror it dont give image of you, but "+
               "something diffent like a workroom of somekind";


set_not_out(1);

}
init() {
  ::init();
  add_action("enter", "enter");
}

enter(str) {
  if(str == "mirror") {
    write("You walk close to mirror and slowly start to examine it.\n"+
          "After short time, when you have gathered enough courage,\n"+
          "you decide to enter it.\n");
    this_player()->move_player("inside the mirror#/wizards/neophyte/areat/castle/workroom.c");
    return 1;
}
write("Enter what?\n");
return 1;
}

