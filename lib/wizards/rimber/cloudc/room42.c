inherit "room/room";

reset(arg) {
 if(arg) return;
 set_light(3);
 short_desc = "Inside the Cloud Castle";
 long_desc = "Stairs and a short corridor.\n";
 add_exit("south", "/wizards/rimber/cloudc/room41.c");
 add_exit("down", "/wizards/rimber/cloudc/room37.c");
 set_not_out(1);
}
