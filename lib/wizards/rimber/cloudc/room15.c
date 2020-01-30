inherit "room/room";

reset(arg) {
 if(arg) return;
 short_desc = "Cloud tower";
 long_desc = "Everything is white.\n";
 set_light(3);
 add_exit("east", "/wizards/rimber/cloudc/room19.c");
 add_exit("south", "/wizards/rimber/cloudc/room16.c");
 add_exit("down", "/wizards/rimber/cloudc/room1.c");
}
