inherit "room/room";

reset(arg) {

  if(arg) return;
  add_exit("north", "/wizards/duncan/sharkisland/virtual_map: 38 21");
 
  short_desc = "A small pier on an island";
  long_desc = "A small wooden pier is built in a huge bay. The bay protects the boats from wind\n"+
              "and storms. The pier is old and a bit brittle. A huge island is towards north.\n"+
              "A big mansion is built in the middle of the island. Two wooden houses can be seen\n"+
              "in the northeast corner and southeast corner of the island. A small half-sunken\n"+
              "ferry is on the right side of the pier. It's fastened to the pier with two ropes.\n"+
              "There are stairs at the end of the pier, leading back to the sea.\n";

    items = allocate(6);
    items[0] = "ropes";
    items[1] = "The ropes are fastened to the half-sunken boat.";
    items[2] = "ferry";
    items[3] = "The ferry is half-sunken. It's fastened to the pier. It's about one and a half\n"+
               "meters away from the pier. The deck of the ship could be reached.";
    items[4] = "stairs";
    items[5] = "Wooden stairs are at the end of the pier. They are leading back to the sea.";

  property = allocate(2);
  property[0] = "no_summon";
  property[1] = "no_tele";

    call_other("wizards/duncan/sharkisland/virtual_map.c", "start_map");
}

init() {
  ::init();
  add_action("jump", "jump");
}
jump(str) {
  if(str != "ferry") return;
write("You jump to the deck of the half-sunken ferry.\n");
say(this_player()->query_name()+" jumps to the deck of the half-sunken ferry.\n");     
     move_object(this_player(),"/wizards/duncan/sharkisland/rooms/ferry/deck.c");
     this_player()->look();
  return 1;
}