inherit "room/room";
object monster;

reset(arg) 
{
  if(arg) return;
  add_exit("north","/wizards/jhary/room/dwarves/dwarf10");
  short_desc = "In an empty house";
  long_desc = "This house is completely empty, except the regular \n"+
              "furniture. There is a bed, a wardrobe, a table with \n"+
              "some chairs and a desk. The room is lighted of some \n"+
              "lamps fixed to the wall, but right now you don't see \n"+
              "anybody in here.\n";
}
                                        
