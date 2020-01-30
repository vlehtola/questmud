inherit "room/room";
object monster;
object monster;
 
reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/grathlek/area4/monsies/nimp.c");
    move_object(monster, this_object());
   }
  add_exit("east","/wizards/grathlek/area4/mroom8.c");
  add_exit("west","/wizards/grathlek/area4/mroom10.c");
  set_light(3);
 
  short_desc = "A shiny red cave.";
  long_desc = "This is the main corridor of this cave.\n"+
              "The rocks on the ground glow red because\n"+
              "the red light shines very brightly from the west\n"+
              "bringing also some warm to this cave.\n";
}
