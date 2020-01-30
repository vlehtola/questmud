inherit "room/room";
object monster;
 
reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/grathlek/area4/monsies/wimp.c");
    move_object(monster, this_object());
   }
  add_exit("east","/wizards/grathlek/area4/mroom2.c");
  add_exit("west","/wizards/grathlek/area4/mroom4.c");
  set_light(2);
 
  short_desc = "A tight red corridor.";
  long_desc = "This is the main corridor of this cave.\n"+
              "There are some mud holes on the ground and\n"+
              "the red light shines from the west. Mighty\n"+
              "pillars stand proudly here.\n";
}
