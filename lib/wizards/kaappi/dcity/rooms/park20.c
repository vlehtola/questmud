inherit "room/room";

reset(status arg) 
{
  if(arg) return;

  add_exit("north", "park17.c");
  add_exit("northeast", "park18.c");
  add_exit("east", "park21.c");
short_desc = "A park";
long_desc = "The trees and bushes are growing straight from the rock.\n"+
            "A beautiful green grass covers the ground. Some most commonly\n"+
            "used paths can clearly be seen on the ground.\n";
  set_light(3);
}
