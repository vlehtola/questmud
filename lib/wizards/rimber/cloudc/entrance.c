inherit "room/room";

reset(arg) {
 if(arg) return;
 short_desc = "In front of the Cloud Gate";
 long_desc = "You stand in front of huge white gate.\n";
 add_exit("leave", "/wizards/rimber/cloudc/land.c");
 add_exit("north", "/wizards/rimber/cloudc/room10.c");
}
