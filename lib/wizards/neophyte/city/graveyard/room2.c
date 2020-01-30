inherit "room/room";
reset(arg) {
if(arg) return;
short_desc = "Pathway inside the graveyard";
long_desc =  "A small trail leaves from pathway and goes west, where is a large tomb.\n"+
             "The northern path is closed and barricades are blocking the way. Green\n"+
             "grass is growing both sides of the path. Different sized tombs and graves\n"+
             "are builded beside the path and below them the ground is little rised.\n";
  add_exit("south", "room1");
  add_exit("west", "room3");
  items = allocate(6);
  items[0] = "chapel";
  items[1] = "The chapel is located in the north side of graveyard and small pathway is going to it but it is barricaded";
  items[2] = "graves";
  items[3] = "They are all different sized and made from different materials";
}