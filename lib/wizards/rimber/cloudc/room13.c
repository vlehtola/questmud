inherit "room/room";

reset(arg) {
 if(arg) return;
 set_light(3);
 short_desc = "In the white tower";
 long_desc = "White stairs lead up.\n";
 add_exit("northwest", "/wizards/rimber/cloudc/room11.c");
 add_exit("up", "/wizards/rimber/cloudc/room29.c");
}
