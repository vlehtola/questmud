inherit "room/room";

reset(status arg) 
{
  if(arg) return;

  add_exit("east", "park6.c");
  add_exit("west", "park4.c");
  add_exit("north", "park7.c");
  add_exit("south", "park2.c");
  add_exit("southeast", "park3.c");
  add_exit("southwest", "park1.c");
short_desc = "A park";
long_desc = "The trees and bushes are growing straight from the rock.\n"+
            "A beautiful green grass covers the ground. Some most commonly\n"+
            "used paths can clearly be seen on the ground. You feel \n"+
            "relaxed as you walk in this park.\n";
  set_light(3);
}
