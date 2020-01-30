inherit "room/room";
inherit "room/door";

reset(arg) {
 if(arg) return;
 set_light(3);
 short_desc = "Inside the Cloud Castle";
 long_desc = "Red walls and pictures.\n";
 add_exit("north", "/wizards/rimber/cloudc/room42.c");
 add_exit("south", "/wizards/rimber/cloudc/room40.c");

 door_reset();
 set_door_label("A red wooden door", 3);
 set_door_dir("east", "/wizards/rimber/cloudc/room30.c", 3);
 set_door_link("/wizards/rimber/cloudc/room30.c", 3);
 set_locked(0, 3);
 set_door_code("009", 3);
}

init() {
 ::init();
 door_init();
 set_not_out(1);
}
