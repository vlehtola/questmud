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

  add_exit("south", "park8.c");
  add_exit("north", "park10.c");
short_desc = "A park";
long_desc = "The trees and bushes are growing straight from the rock.\n"+
            "A beautiful green grass covers the ground. Some most commonly\n"+
            "used paths can clearly be seen on the ground.\n";
  set_light(3);
}
