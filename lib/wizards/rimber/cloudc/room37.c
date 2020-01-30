inherit "room/room";

reset(arg) {
 if(arg) return;
 set_light(3);
 short_desc = "Inside the Cloud Castle";
 long_desc = "Stairs jne.\n";
 add_exit("north", "/wizards/rimber/cloudc/room36.c");
 add_exit("up", "/wizards/rimber/cloudc/room42.c");
 set_not_out(1);
}
