inherit "room/room";
int door = 0;

reset(arg) {
 if(arg) return;
 set_light(3);
 short_desc = "Before a wooden door";
 long_desc = "A narrow bridge leads north to the wall. A huge wooden door stands in the\n"+
  "middle of the huge white mass which looks like a house. Next to the door is a\n"+
  "small golden bell hanging in the air.\n";
  items = allocate(2);
  items[0] = "bell";
  items[1] = "Maybe you shoueld ring it?\n";
 add_exit("north", "/wizards/rimber/cloudc/room32.c");
}

init() {
 ::init();
 add_action("ring", "ring");
}

ring(str) {
 if(str == "bell") {
 if(door == 1) { write("The door is already open.\n"); }
 if(door == 0) {
  write("The door swings open when you ring the bell.\n");
  add_exit("enter", "/wizards/rimber/cloudc/room34.c");
 door = 1;
 }
 }
 else { write("Ring what?\n"); }
 return 1;
}
