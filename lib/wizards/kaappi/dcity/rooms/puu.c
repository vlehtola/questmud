inherit "room/room";

reset(status arg) 
{
  if(arg) return;

  add_exit("down", "park7.c");
short_desc = "An old oak";
long_desc = "You climbed up on the tree and now you can see almost\n"+
            "whole of the city. A gorgeous looking city hall is rising on\n"+
            "the right side of you. Many citizens are walking around the streets.\n"+
            "There is something behind of the bushes in north.\n";
  set_light(3);
}
