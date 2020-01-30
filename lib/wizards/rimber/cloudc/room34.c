inherit "room/room";

reset(arg) {
 if(arg) return;
 set_light(3);
 short_desc = "Inside the Cloud Castle";
 long_desc = "A long white corridor goes south. A red carpet lies on the floor all the way\n"+
  "down the corridor.\n";
 add_exit("south", "/wizards/rimber/cloudc/room35.c");
 add_exit("out", "/wizards/rimber/cloudc/room33.c");
 set_not_out(1);
}
