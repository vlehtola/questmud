inherit "room/room";

reset(status arg) 
{
  if(arg) return;

  add_exit("north", "park16.c");
  add_exit("west", "park17.c");
  add_exit("east", "park19.c");
  add_exit("southwest", "park20.c");
  add_exit("south", "park21.c");
  add_exit("southeast", "park22.c");
short_desc = "A park";
long_desc = "The trees and bushes are growing straight from the rock.\n"+
            "A beautiful green grass covers the ground. Some most commonly\n"+
            "used paths can clearly be seen on the ground. You feel \n"+
            "relaxed as you walk in this park.\n";
  set_light(3);
}
