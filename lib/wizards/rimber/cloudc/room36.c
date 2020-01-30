inherit "room/room";
inherit "room/door";

reset(arg) {
 if(arg) return;
 set_light(3);
 short_desc = "Inside the Cloud Castle";
 long_desc = "plaaplaaplaa\n";
 add_exit("north", "/wizards/rimber/cloudc/room35.c");
 add_exit("south", "/wizards/rimber/cloudc/room37.c");
 door_reset();
 set_door_label("A white steel door", 1);
 set_door_label("A white silver door", 2);
 set_door_dir("west", "/wizards/rimber/cloudc/room47.c", 1);
 set_door_dir("east", "/wizards/rimber/cloudc/room38.c", 2);
 set_door_code("878", 1);
 set_door_code("222", 2);
 set_locked(1, 1);
 set_locked(1, 2);
 set_door_link("/wizards/rimber/cloudc/room47.c", 1);
 set_door_link("/wizards/rimber/cloudc/room38.c", 2);
}

init() {
 ::init();
 door_init();
 set_not_out(1);
}
