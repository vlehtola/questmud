inherit "room/room";
reset(arg) {
if(arg) return;
add_exit("south","/wizards/trooper/workroom.c");
short_desc = "Outside the city";
long_desc = "Deep moat prevents you entering the city.\n"+
            "Other side of the moat is a guard. A tiny rock is on the ground, \n" +
	    "strange.\n";
items = allocate(2);
items[0] = "rock";
items[1] = "Tiny round rock... pebble would be better this so small.";
}
init() {
  ::init();
  add_action("throw", "throw");
}
throw(str) {
  if(str != "rock at guard") return;
  write("You throw the pebble with all your might.... and you SCORE!!!\n"+
         "Guard shouts something angrily but lowers the bridge.\n");
   add_exit("north", "wizards/trooper/areas/muhoscity/r1.c");
  return 1;
}

