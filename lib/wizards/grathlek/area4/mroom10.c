inherit "room/room";
object monster;
 
reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/grathlek/area4/monsies/wgimp.c");
    move_object(monster, this_object());
   }
  add_exit("east","/wizards/grathlek/area4/mroom9.c");
  add_exit("west","/wizards/grathlek/area4/mroom11.c");
  add_exit("southeast","/wizards/grathlek/area4/froom7.c");
  add_exit("northeast","/wizards/grathlek/area4/croom9.c");
  set_light(3);
 
  short_desc = "A rocky path leading to west.";
  long_desc = "This is the main corridor of this cave.\n"+
              "The path is covered by a red glow like it\n"+
              "would be a stream of blood. Red light shines\n"+
              "very brightly from the west.\n";
}
