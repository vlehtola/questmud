inherit "room/room";
object mob,mob2;

reset(arg) {

if(!mob) {
  mob = clone_object("/wizards/kaappi/dcity/mobs/kids.c");
  move_object(mob, this_object()); }

if(!mob2) {
  mob2 = clone_object("/wizards/kaappi/dcity/mobs/kids.c");
  move_object(mob2, this_object()); }

  if(arg) return;

  add_exit("west", "park5.c");
  add_exit("south", "park3.c");
  add_exit("southwest", "park2.c");
short_desc = "A park";
long_desc = "The trees and bushes are growing straight from the rock.\n"+
            "A beautiful green grass covers the ground. Some most commonly\n"+
            "used paths can clearly be seen on the ground. You feel \n"+
            "relaxed as you walk in this park.\n";
  set_light(3);
}
