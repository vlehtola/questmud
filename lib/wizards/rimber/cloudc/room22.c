inherit "room/room";

reset(arg) {
 if(arg) return;
 short_desc = "Cloud tower";
 long_desc = "Everything is white.\n";
 set_light(3);
 add_exit("west", "/wizards/rimber/cloudc/room21.c");
 add_exit("south", "/wizards/rimber/cloudc/room23.c");
 add_exit("down", "/wizards/rimber/cloudc/room2.c");
}
