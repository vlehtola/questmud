inherit "room/room";
object mon, mon1;

reset(arg) {
 if(!mon) {
 mon = clone_object("/wizards/rimber/cloudc/mobs/soldier.c");
 move_object(mon, this_object());
 }
 if(!mon1) {
 mon1 = clone_object("/wizards/rimber/cloudc/mobs/soldier.c");
 move_object(mon1, this_object()); }
 if(arg) return;
 set_light(3);
 short_desc = "In the castle yard";
 long_desc = "Everything is white.\n";
 add_exit("north", "/wizards/rimber/cloudc/room6.c");
 add_exit("northeast", "/wizards/rimber/cloudc/room7.c");
 add_exit("east", "/wizards/rimber/cloudc/room10.c");
 add_exit("southwest", "/wizards/rimber/cloudc/room12.c");
}
