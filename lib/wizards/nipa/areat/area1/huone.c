inherit "room/room";

reset(arg) 
{
  add_exit("north","/wizards/nipa/newroom");
  add_exit("east","/wizards/nipa/newroom");
  add_exit("south","/wizards/nipa/newroom");
  add_exit("west","/wizards/nipa/newroom");

  short_desc = "Cave. Its very dark in here.";
  long_desc = "This is very dark cave. Huge stone seems to be blocking\n"+
              "your path. Believe it or not.\n";

   set_light(3);
  
  items = allocate(2);
  items[0] = "stone";
  items[1] = "Huge stone blocking the path";
}
