inherit "room/room";
object mosa, mosa1, guard;
string DIR = "/wizards/rimber/hell/";

reset(arg) {
 if(!guard) {
 guard = clone_object("/wizards/rimber/hell/mobs/guard2.c");
 move_object(guard, this_object());
 }
 if(!mosa) {
 mosa = clone_object("/wizards/rimber/hell/mobs/demon.c");
 move_object(mosa, this_object());
 }
 if(!mosa1) {
 mosa1 = clone_object("/wizards/rimber/hell/mobs/demon.c");
 move_object(mosa1, this_object());
 } 
 if(arg) return;
 set_light(3);
 set_not_out(1);
 short_desc = "Highway to hell";
 long_desc = "A wide path from south to north. Lava flows slowly on both sides of the path.\n";
 add_exit("down", DIR+"room12a.c");
 add_exit("south", DIR+"room9.c");
}
