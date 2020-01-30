inherit "room/room";
object monster;
 
reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/grathlek/area4/monsies/dimp.c");
    move_object(monster, this_object());
   }
  add_exit("east","/wizards/grathlek/area4/froom3.c");
  add_exit("west","/wizards/grathlek/area4/froom5.c");
  add_exit("northwest","/wizards/grathlek/area4/mroom7.c");
  set_light(2);
 
  short_desc = "A smelly red junction.";
  long_desc = "There is so much mud on the ground that\n"+
              "it's hard to move or fight here.\n"+ 
              "Air is musty and breathing is hard.\n"+
              "Some slimy lizards crawl on the ground\n";
}
