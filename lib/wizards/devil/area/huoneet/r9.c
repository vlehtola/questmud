inherit "room/room";
object monster,monster2;

reset(arg) {
  if(!present("ghost")) { 
    move_object(clone_object("/wizards/devil/area/mobit/ghost.c"), this_object());
    move_object(clone_object("/wizards/devil/area/mobit/ghost.c"), this_object());
}  

  if(arg) return;

  add_exit("north","/wizards/devil/area/huoneet/r10.c");
  add_exit("south","/wizards/devil/area/huoneet/r8.c");
 set_light(2);
  short_desc = "Small sand path in the graveyard";
  long_desc = "You are walking on the small sand path which is leading to the centre of the\n"+
              "graveyard. Some fireflies fly about here, softly lighting the surroundings.\n"+
              "You can notice some red and scary looking eyes gazing at you behind the\n"+
              "gravestones. There are some footsteps on the ground. If you look straight\n"+ 
              "ahead you can notice some movement in the shadows. Creepy screaming echoes\n"+
              "around the graveyard.\n";

}
