inherit "room/room";
object monster;
 
reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/grathlek/area4/monsies/uimp.c");
    move_object(monster, this_object());
   }
  add_exit("southeast","/wizards/grathlek/area4/froom1.c");
  add_exit("west","/wizards/grathlek/area4/froom3.c");
  add_exit("southwest","/wizards/grathlek/area4/wroom1.c");
  set_light(2);
 
  short_desc = "A garbage heap.";
  long_desc = "This is the place where the dead imps\n"+
              "end their journey if they won't get eaten\n"+ 
              "by their relatives. The place is somewhat\n"+
              "magical and it creates awful undeads.\n";
}
