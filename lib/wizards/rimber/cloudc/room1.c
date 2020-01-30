inherit "room/room";

reset(arg) {
 if(arg) return;
 set_light(3);
 short_desc = "In the white tower";
 long_desc = "White stairs leads up from the soft white ground. Light blue\n"+
 "shadows fall on the white surfaces revealing shapes.\n";
 add_exit("southeast", "/wizards/rimber/cloudc/room3.c");
 add_exit("up", "/wizards/rimber/cloudc/room15.c");
}
