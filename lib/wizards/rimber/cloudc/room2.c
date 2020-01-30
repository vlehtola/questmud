inherit "room/room";

reset(arg) {
 if(arg) return;
 set_light(3);
 short_desc = "In the white tower";
 long_desc = "White stairs lead up.\n";
 add_exit("southwest", "/wizards/rimber/cloudc/room5.c");
 add_exit("up", "/wizards/rimber/cloudc/room22.c");
}
