inherit "room/room";
object mike;

reset(arg) {
 if(!mike) {
 mike = clone_object("/wizards/rimber/cloudc/mobs/mike.c");
 move_object(mike, this_object());
 }
 if(arg) return;
 set_light(3);
 short_desc = "In the Cloud Tower";
 long_desc = "Only walls and cracks.\n";
 add_exit("down", "/wizards/rimber/cloudc/room44.c");
 set_not_out(1);
}
