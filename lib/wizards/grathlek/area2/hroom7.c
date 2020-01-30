inherit "room/room";

 
reset(arg) {
  add_exit("east","/wizards/grathlek/area2/hrooma.c");
  add_exit("west","/wizards/grathlek/area2/hroom6.c");
  set_light(0); 
  
  short_desc = "In the corridors of the dark labyrhint.";
  long_desc = "The walls of the corridors are made of\n"+
              "skulls and bones. You can feel the presense\n"+
              "of great evil. It is really cold and dark in here.\n"; 
}
