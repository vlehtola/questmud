inherit "room/room";
object mosa, mosa1;
string DIR = "/wizards/rimber/hell/";

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
 set_light(3);
 set_not_out(1);
 short_desc = "Highway to hell";
 long_desc = "A wide path from south to north. Lava flows slowly on both sides of the path.\n";
 add_exit("north", DIR+"room11.c");
 add_exit("southwest", DIR+"room5.c");
}
