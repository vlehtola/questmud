inherit "room/room";
object mon, mon1;

reset(arg) {
 if(!mon) {
 mon = clone_object("/wizards/rimber/cloudc/mobs/soldier.c");
 move_object(mon, this_object()); }
 if(!mon1) {
 mon1 = clone_object("/wizards/rimber/cloudc/mobs/soldier.c");
 move_object(mon1, this_object()); }
 if(arg) return;
 set_light(3);
 short_desc = "In the castle yard";
 long_desc = "Everything is white.\n";
 add_exit("northeast", "/wizards/rimber/cloudc/room2.c");
 add_exit("west", "/wizards/rimber/cloudc/room4.c");
 add_exit("southwest", "/wizards/rimber/cloudc/room7.c");
 add_exit("south", "/wizards/rimber/cloudc/room8.c");
 add_exit("southwest", "/wizards/rimber/cloudc/room8.c");
}
