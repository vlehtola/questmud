inherit "room/room";

reset(arg) {
 if(arg) return;
 short_desc = "Cloud tower";
 long_desc = "Everything is white.\n";
 set_light(3);
 add_exit("north", "/wizards/rimber/cloudc/room18.c");
 add_exit("east", "/wizards/rimber/cloudc/room26.c");
 add_exit("down", "/wizards/rimber/cloudc/room12.c");
}
