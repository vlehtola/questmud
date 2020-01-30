inherit "room/room";
object monster;
 
reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/grathlek/area4/monsies/famu.c");
    move_object(monster, this_object());
   }
  add_exit("east","/wizards/grathlek/area4/mroom3.c");
  add_exit("west","/wizards/grathlek/area4/mroom5.c");
  add_exit("northwest","/wizards/grathlek/area4/croom5.c");
  set_light(2);
 
  short_desc = "A filthy red junction.";
  long_desc = "This is the main corridor of this cave.\n"+
              "The ground looks somewhat muddy and the\n"+
              "red light shines from the west. Walls\n"+
              "are covered by some stones.\n";
}
