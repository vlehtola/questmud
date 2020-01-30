inherit "room/room";

 
reset(arg) {
  add_exit("south","/wizards/grathlek/area2/hroom3.c");
  add_exit("north","/wizards/grathlek/area2/hroom1.c");
  set_light(0); 
  
  short_desc = "In the corridors of the dark labyrhint.";
  long_desc = "The walls of the corridors are made of\n"+
              "skulls and bones. You can feel the presense\n"+
              "of great evil. It is really cold and dark in here.\n"; 
}
