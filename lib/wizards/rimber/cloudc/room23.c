inherit "room/room";

reset(arg) {
 if(arg) return;
 short_desc = "On the wall";
 long_desc = "Everything is white.\n";
 set_light(3);
 add_exit("north", "/wizards/rimber/cloudc/room22.c");
 add_exit("south", "/wizards/rimber/cloudc/room24.c");
}
