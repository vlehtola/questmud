inherit "room/room";
object monster;
 
reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/grathlek/area2/monsies/sscav.c");
    move_object(monster, this_object());
   }
  add_exit("south","/wizards/grathlek/area2/hroom2.c");
  add_exit("north","/wizards/grathlek/area2/hroom.c");
  set_light(0); 
  
  short_desc = "In the corridors of the dark labyrhint.";
  long_desc = "The walls of the corridors are made of\n"+
              "skulls and bones. You can feel the presense\n"+
              "of great evil. It is really cold and dark in here.\n"; 
}
