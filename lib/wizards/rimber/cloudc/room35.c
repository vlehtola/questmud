inherit "room/door";
inherit "room/room";


reset(arg) {
 if(arg) return;
 door_reset();
 set_door_label("A black wooden door", 1);
 set_door_label("A black iron door", 2);
 set_door_dir("west", "/wizards/rimber/cloudc/room39.c", 1);
 set_door_dir("east", "/wizards/rimber/cloudc/room46.c", 2);
 set_door_code("101", 1);
 set_door_code("020", 2);
 set_locked(1, 1);
 set_locked(1, 2);
 set_light(3);
 short_desc = "Inside the Cloud Castle";
 long_desc = "A long white corridor goes south. A red carpet lies on the floor all the way\n"+
 "down the corridor.\n";
 add_exit("north", "/wizards/rimber/cloudc/room34.c");
 add_exit("south", "/wizards/rimber/cloudc/room36.c");
 set_door_link("/wizards/rimber/cloudc/room39.c", 1);
}

init() {
 ::init();
 door_init();
 set_not_out(1);
}
