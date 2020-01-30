inherit "room/room";

reset(status arg) 
{
  if(arg) return;

  add_exit("east", "park13.c");
  add_exit("west", "park11.c");
short_desc = "A park";
long_desc = "The trees and bushes are growing straight from the rock.\n"+
            "A beautiful green grass covers the ground. Some most commonly\n"+
            "used paths can clearly be seen on the ground. You feel \n"+
            "relaxed as you walk in this park.\n";
  set_light(3);
}
