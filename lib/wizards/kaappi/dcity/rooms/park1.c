inherit "room/room";
object mob,qmob;

reset(arg) {

if(!qmob) {
  qmob = clone_object("/wizards/kaappi/dcity/mobs/qlapsi.c");
  move_object(qmob, this_object()); }

if(!mob) {
  mob = clone_object("/wizards/kaappi/dcity/mobs/kids.c");
  move_object(mob, this_object()); }
  if(arg) return;

  add_exit("east", "park2.c");
  add_exit("northeast", "park5.c");
  add_exit("north", "park4.c");
short_desc = "A park";
long_desc = "The trees and bushes are growing straight from the rock.\n"+
            "A beautiful green grass covers the ground. Some most commonly\n"+
            "used paths can clearly be seen on the ground. You feel \n"+
            "relaxed as you walk in this park.\n";
  set_light(3);
}