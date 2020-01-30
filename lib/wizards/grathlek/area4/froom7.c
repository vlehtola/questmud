inherit "room/room";
object monster;
 
reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/grathlek/area4/monsies/wimp.c");
    move_object(monster, this_object());
   }
  add_exit("east","/wizards/grathlek/area4/froom6.c");
  add_exit("northwest","/wizards/grathlek/area4/mroom10.c");
  set_light(2);
 
  short_desc = "A red shining junction.";
  long_desc = "The red light flares everywhere\n"+
              "and your imagination creates horrible\n"+ 
              "fire monsters on the walls of the cave.\n";
}
