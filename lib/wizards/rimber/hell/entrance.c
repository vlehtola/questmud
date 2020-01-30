inherit "room/door";
inherit "room/room";
object mosa;

reset(arg) {
 if(!mosa) {
 mosa = clone_object("/wizards/rimber/hell/mobs/cerberos.c");
 move_object(mosa, this_object());
 }
 if(arg) return;
 door_reset();
 set_light(3);
 set_door_label("A massive iron door", 1);
 set_door_dir("north", "/wizards/rimber/hell/room1.c", 1);
 set_door_code("666", 1);
 set_locked(1, 1);
 short_desc = "At the gates of the hell";
 long_desc = "A huge iron gate lies before you.\n";
 add_exit("out", "/wizards/rimber/cloudc/land.c");
 set_door_link("/wizards/rimber/hell/room1.c", 1);
}

init() {
 ::init();
 door_init();
}
