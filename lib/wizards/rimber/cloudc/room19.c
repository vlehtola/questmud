inherit "room/room";

reset(arg) {
 if(arg) return;
 short_desc = "On the wall";
 long_desc = "Everything is white.\n";
 set_light(3);
 add_exit("west", "/wizards/rimber/cloudc/room15.c");
 add_exit("east", "/wizards/rimber/cloudc/room20.c");
}
