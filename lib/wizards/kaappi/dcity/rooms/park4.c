inherit "room/room";
object mob;

reset(arg) {
  if(arg) return;

if(!mob) {
  mob = clone_object("/wizards/kaappi/dcity/mobs/boltak.c");
  move_object(mob, this_object()); }

  add_exit("south", "park1.c");
  add_exit("southeast", "park2.c");
  add_exit("east", "park5.c");
short_desc = "A park";
long_desc = "The trees and bushes are growing straight from the rock.\n"+
            "A beautiful green grass covers the ground. Some most commonly\n"+
            "used paths can clearly be seen on the ground.\n";
  set_light(3);
}
