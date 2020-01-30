inherit "room/room";

reset(status arg) 
{
  if(arg) return;

   add_exit("southeast", "r18.c");
   add_exit("west", "r20.c");
short_desc = "A tunnel";
   long_desc = "This part of the tunnel looks quite new. Marks of\n"+
               "mining can clearly see. Walls are full of cracks and \n"+
               "holes. Some small pieces of mithril can be seen on \n"+
               "the walls. There are many dwarven miners working and \n"+
               "running everywhere.\n";
set_light(1);
}
