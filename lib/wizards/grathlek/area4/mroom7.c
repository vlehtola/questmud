inherit "room/room";
object monster;
 
reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/grathlek/area4/monsies/cimp.c");
    move_object(monster, this_object());
   }
  add_exit("east","/wizards/grathlek/area4/mroom6.c");
  add_exit("west","/wizards/grathlek/area4/mroom8.c");
  add_exit("southeast","/wizards/grathlek/area4/froom4.c");
  set_light(2);
 
  short_desc = "A red junction.";
  long_desc = "This is the main corridor of this cave.\n"+
              "The ground here looks solid and rocky.\n"+
              "Red light shines very brightly from the west\n"+
              "and there is no such plant that could survive\n"+
              "in this dry rocky cave.\n";
}
