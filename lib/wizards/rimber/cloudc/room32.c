inherit "room/room";
object mon;

reset(arg) {
 if(arg) return;
 if(!mon) {
 mon = clone_object("/wizards/rimber/cloudc/mobs/guard.c");
 move_object(mon, this_object()); }
 set_light(3);
 short_desc = "On a bridge";
 long_desc = "A narrow bridge from the wall.\n";
 add_exit("north", "/wizards/rimber/cloudc/room20.c");
 add_exit("south", "/wizards/rimber/cloudc/room33.c");
}
