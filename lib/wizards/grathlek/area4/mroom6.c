inherit "room/room";
object monster;
 
reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/grathlek/area4/monsies/dimp.c");
    move_object(monster, this_object());
   }
  add_exit("east","/wizards/grathlek/area4/mroom5.c");
  add_exit("west","/wizards/grathlek/area4/mroom7.c");
  set_light(2);
 
  short_desc = "A tight red passage.";
  long_desc = "This is the main corridor of this cave.\n"+
              "You must beware on mudholes in this tight cave.\n"+
              "Red light shines brightly from the west making\n"+
              "the mud look like blood.\n";
}
