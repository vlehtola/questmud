inherit "room/room";  

reset(arg) {
if(!present("ghost")) { 
    move_object(clone_object("/wizards/devil/area/mobit/ghost.c"), this_object());
    move_object(clone_object("/wizards/devil/area/mobit/ghost.c"), this_object());
}
  add_exit("west","/wizards/devil/area/huoneet/r15.c");
  add_exit("east","/wizards/devil/area/huoneet/r13.c");
 set_light(2);
  short_desc = "Small sand path in the graveyard";
  long_desc = "You are walking on the small sand path which is leading to the centre of the\n"+
              "graveyard. Some fireflies fly about here, softly lighting the surroundings.\n"+
              "You can notice some red and scary looking eyes gazing at you behind the\n"+
              "gravestones. There are some footsteps on the ground. If you look straight\n"+   
              "ahead you can notice some movement in the shadows. Creepy screaming echoes\n"+
              "around the graveyard.\n";

}
