inherit "room/room";
object mon;

reset(arg) {
 if(!mon) {
 mon = clone_object("/wizards/rimber/cloudc/mobs/soldier.c");
 move_object(mon, this_object()); }
 if(arg) return;
 set_light(3);
 short_desc = "In the castle yard";
 long_desc = "Everything is white.\n";
 add_exit("northwest", "/wizards/rimber/cloudc/room1.c");
 add_exit("east", "/wizards/rimber/cloudc/room4.c");
 add_exit("south", "/wizards/rimber/cloudc/room6.c");
 add_exit("southeast", "/wizards/rimber/cloudc/room7.c");
 add_exit("southeast", "/wizards/rimber/cloudc/room7.c");
}
