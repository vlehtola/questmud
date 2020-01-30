inherit "room/room";
object monster;
 
reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/grathlek/area4/monsies/wimp.c");
    move_object(monster, this_object());
   }
  add_exit("east","/wizards/grathlek/area4/froom5.c");
  add_exit("west","/wizards/grathlek/area4/froom7.c");
  add_exit("southeast","/wizards/grathlek/area4/wroom3.c");
  set_light(2);
 
  short_desc = "A muddy red junction.";
  long_desc = "Some mud holes cover the ground and\n"+
              "you must be careful not to fall in one\n"+ 
              "of those. Ugly grawling lizards on the\n"+
              "mud holes might get a proper meal from you.\n";
}
