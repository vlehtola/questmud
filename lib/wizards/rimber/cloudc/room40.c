inherit "room/room";

reset(arg) {
 if(arg) return;
 set_light(3);
 short_desc = "Inside the Cloud Castle";
 long_desc = "A narrow staircase and a bloody carpet.\n";
 add_exit("north", "/wizards/rimber/cloudc/room41.c");
 add_exit("stairs", "/wizards/rimber/cloudc/room43.c");
 set_not_out(1);
}
