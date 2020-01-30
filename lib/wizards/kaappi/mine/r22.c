inherit "room/room";

reset(status arg) 
{
  if(arg) return;

   add_exit("north", "r21.c");
   add_exit("northeast", "r23.c");
   add_exit("southwest", "r25.c");
short_desc = "A tunnel";
   long_desc = "This part of the tunnel looks quite new. Marks of\n"+
               "mining can clearly see. Walls are full of cracks and \n"+
               "holes. Some small pieces of mithril can be seen on \n"+
               "the walls. There are many dwarven miners working and \n"+
               "running everywhere.\n";
set_light(1);
}
