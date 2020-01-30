inherit "room/room";
object monster;
 
reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/grathlek/area4/monsies/dimp.c");
    move_object(monster, this_object());
   }
  add_exit("east","/wizards/grathlek/area4/froom3.c");
  add_exit("west","/wizards/grathlek/area4/froom6.c");
  add_exit("northwest","/wizards/grathlek/area4/mroom7.c");
  set_light(2);
 
  short_desc = "A smelly red passage.";
  long_desc = "This is the slum area where imps\n"+
              "grub their food from the garbage heap.\n"+ 
              "Air is musty and breathing is hard. Tiny\n"+
              "blue and pink worms crawl on the ground\n";
}
