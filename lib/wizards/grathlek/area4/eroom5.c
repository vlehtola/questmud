inherit "room/room";
object monster;
 
reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/grathlek/area4/monsies/wimp.c");
    move_object(monster, this_object());
   }
  add_exit("northeast","/wizards/grathlek/area4/eroom4.c");
  add_exit("west","/wizards/grathlek/area4/froom1.c");
  set_light(2);
 
  short_desc = "A bad smelling filthy passage.";
  long_desc = "Red light glows on the walls of the cave.\n"+
              "The smell in here hurts your nose and makes\n"+
              "you wanna leave. Rats run in the shadows and\n"+
              "there is something rotting near.\n";
}
