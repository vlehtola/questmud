inherit "room/room";
object monster;
 
reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/grathlek/area4/monsies/gimp.c");
    move_object(monster, this_object());
   }
  add_exit("east","/wizards/grathlek/area4/mroom1.c");
  add_exit("west","/wizards/grathlek/area4/mroom3.c");
  add_exit("northeast","/wizards/grathlek/area4/croom1.c");
  set_light(2);
 
  short_desc = "A red junction.";
  long_desc = "This is the main corridor of this cave.\n"+
              "The corridor is muddy and filthy and the\n"+
              "red light shines from the west. The supporting\n"+
              "pillars here have sinked into this vulcanic ground.\n";
}
