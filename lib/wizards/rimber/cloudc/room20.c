inherit "room/room";

reset(arg) {
 if(arg) return;
 short_desc = "On the wall";
 long_desc = "Everything is white.\n";
 set_light(3);
 add_exit("west", "/wizards/rimber/cloudc/room19.c");
 add_exit("east", "/wizards/rimber/cloudc/room21.c");
 add_exit("south", "/wizards/rimber/cloudc/room32.c");
}
