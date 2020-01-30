inherit "room/room";

reset(arg) {
if(arg) return;

add_exit("north", "out:");
add_exit("south", "out:");
add_exit("west", "out:");
add_exit("east", "out:");

short_desc = "A small opening on the mountainside";
long_desc = "A huge mountain rises from here trying to reach the sky. The mountain wall is\n"+ 
            "upright and smooth watering down the possible climbing attempts. A small\n"+
            "opening can be seen on the mountainside couple meters above the ground. The\n"+
            "wall around the opening is frozen and covered with thick layer of ice and\n"+
            "snow. There is a small ledge in front of the opening but it's out of reach. The\n"+
            "ledge is covered with thin layer of snow. A strange blue light is shimmering\n"+
            "from the opening. The cold air which is floating out from the opening is\n"+
            "freezing your lungs making your vital functions faster. A thin crack is running\n"+
            "down from the ledge touching almost the ground.\n";

   items = allocate(4);
   items[0] = "ledge";
   items[1] = "A small ledge is couple meters above the ground in front of the opening on the mountainside. It's impossible to climb up on the ledge, because the mountain wall is upright and smooth";
   items[2] = "crack";
   items[3] = "A thin crack runs down from the ledge reaching almost the ground. It might be used as a stairs to the ledge";

 call_other("wizards/duncan/icecaves/daemon/drop_icicle_d.c", "start_rocks", 1);
 call_other("wizards/duncan/icecaves/daemon/slip_d.c", "start_slipping", 1);
}

init() {
  ::init(); 
  add_action("climb", "climb"); 
}

climb(str) {
  if(str == "crack") {
    write("You climb up to the ledge using the crack as stairs.\n"); 
    say(this_player()->query_name()+" climbs up to the ledge using the crack as stairs.\n");
    move_object(this_player(),"/wizards/duncan/icecaves/ledge.c");
    command("look",this_player());
     }
     return 1;
 }
