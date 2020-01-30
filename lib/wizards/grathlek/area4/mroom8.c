inherit "room/room";
object monster;
 
reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/grathlek/area4/monsies/dimp.c");
    move_object(monster, this_object());
   }
  add_exit("east","/wizards/grathlek/area4/mroom7.c");
  add_exit("west","/wizards/grathlek/area4/mroom9.c");
  add_exit("northeast","/wizards/grathlek/area4/croom7.c");
  set_light(3);
 
  short_desc = "A red glowing junction.";
  long_desc = "This is the main corridor of this cave.\n"+
              "The ground is covered by big rocks which are\n"+
              "from the mighty collapsed pillars which where\n"+
              "once supporting this cave. Red light shines \n"+
              "very brightly from the west.\n";
}
