inherit "room/room";
object mosa, mosa1;

reset(arg) {
 if(!mosa) {
 mosa = clone_object("/wizards/rimber/hell/mobs/demon.c");
 move_object(mosa, this_object());
 }
 if(!mosa1) {
 mosa1 = clone_object("/wizards/rimber/hell/mobs/demon.c");
 move_object(mosa1, this_object());
 }
 if(arg) return;
 set_light(2);
 set_not_out(1);
 short_desc = "Hell";
 long_desc = "A wide stone path leads north. Lava flows on both sides of the path.\n";
 add_exit("north", "/wizards/rimber/hell/room2.c");
 add_exit("south", "/wizards/rimber/hell/entrance.c");
}
