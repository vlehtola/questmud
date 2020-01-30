inherit "room/room";
object mon1, mon2, mon3;

reset(arg) {
 if(!mon3) {
 mon3 = clone_object("/wizards/rimber/cloudc/mobs/rider.c");
 move_object(mon3, this_object()); }
 if(!mon1) {
 mon1 = clone_object("/wizards/rimber/cloudc/mobs/stormbird.c");
 move_object(mon1, this_object());
 }
 if(!mon2) {
 mon2 = clone_object("/wizards/rimber/cloudc/mobs/stormbird.c");
 move_object(mon2, this_object());
 }
 if(arg) return;
 set_light(3);
 short_desc = "In a snow white stable";
 long_desc = "Everything is white. Some large yellow feathers lie on the ground.\n";
 add_exit("west", "/wizards/rimber/cloudc/room8.c");
}
