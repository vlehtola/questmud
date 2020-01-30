inherit "room/room";

reset(arg) {
 if(arg) return;
 short_desc = "Cloud tower";
 long_desc = "Everything is white.\n";
 set_light(3);
 add_exit("west", "/wizards/rimber/cloudc/room28.c");
 add_exit("north", "/wizards/rimber/cloudc/room25.c");
 add_exit("down", "/wizards/rimber/cloudc/room13.c");
}
