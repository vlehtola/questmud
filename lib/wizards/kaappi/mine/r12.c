inherit "room/room";

reset(status arg) 
{
  if(arg) return;

   add_exit("south", "r7.c");
   add_exit("west", "r11.c");
short_desc = "A tunnel";
long_desc = "Older parts of these tunnels. A thin layer\n"+ 
              "of dust covers the floor and a lot of footprints can be\n"+
              "seen. There are many dwarven miners running everywhere.\n";
  set_light(1);
}
