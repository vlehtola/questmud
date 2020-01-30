inherit "room/room";
object guard, guard1;

reset(arg) {
 if(arg) return;
 if(!guard) {
 guard = clone_object("/wizards/rimber/cloudc/mobs/guard.c");
 move_object(guard, this_object());
 }
 if(!guard1) {
 guard1 = clone_object("/wizards/rimber/cloudc/mobs/guard.c");
 move_object(guard1, this_object()); }
 set_light(3);
 short_desc = "In the Cloud Tower";
 long_desc = "Small tunnel leads south. Bright white walls.\n";
 add_exit("south", "/wizards/rimber/cloudc/room44.c");
 add_exit("stairs", "/wizards/rimber/cloudc/room40.c");
 set_not_out(1);
}
