inherit "room/room";
object monster;
 
reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/grathlek/area4/monsies/famu.c");
    move_object(monster, this_object());
   }
  add_exit("east","/wizards/grathlek/area4/mroom4.c");
  add_exit("west","/wizards/grathlek/area4/mroom6.c");
  set_light(2);
 
  short_desc = "A muddy red passage.";
  long_desc = "This is the main corridor of this cave.\n"+
              "There are mudholes all over the ground and\n"+
              "the red light shines brightly from the west.\n"+
              "Some bones lay on the shadows.\n";
}
