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
 add_exit("west", "/wizards/rimber/cloudc/room3.c");
 add_exit("east", "/wizards/rimber/cloudc/room5.c");
 add_exit("southwest", "/wizards/rimber/cloudc/room6.c");
 add_exit("south", "/wizards/rimber/cloudc/room7.c");
 add_exit("southeast", "/wizards/rimber/cloudc/room8.c");
}
