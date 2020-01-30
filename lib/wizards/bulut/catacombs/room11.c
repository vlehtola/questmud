inherit "room/room";

init() {
  add_action("drink","drink");
::init();
}

reset(arg) {


  add_exit("south","/wizards/bulut/catacombs/room7");
  add_exit("west","/wizards/bulut/catacombs/room10");
  short_desc = "Ancient graveyard";
  long_desc = "You are standing on a peaceful grass field.\n" +
              "No one seems to be taking care of this old graveyard.\n" +
	      "A tiny stream runs down from the stony soil on eastwards.\n"; 

 set_light(2);                 

items = allocate(2);

 items[0] = "stream";
 items[1] = "A tiny stream. The water looks clean enough to drink";
}

drink(str) {
if(str=="stream") {
  write("You take a sip from the stream.\n");
  this_player()->drink_soft(2000);           
  return 1;
}
return 0;
}                                               