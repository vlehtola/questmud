inherit "room/room";  

reset(arg) {
if(!present("ghost")) { 
    move_object(clone_object("/wizards/devil/area/mobit/ghost.c"), this_object());
    move_object(clone_object("/wizards/devil/area/mobit/ghost.c"), this_object());
}
  add_exit("west","/wizards/devil/area/huoneet/r6.c");
  add_exit("east","/wizards/devil/area/huoneet/r4.c");
 set_light(2);
  short_desc = "Small sand path in the graveyard";
  long_desc = "You are walking on the small sand path which is leading to the centre of the\n"+
              "graveyard. Some fireflies fly about here, softly lighting the surroundings.\n"+
              "The misty wind is blowing some leaves in here. If you look straight ahead you\n"+   
              "can notice somemovement in the shadows. The ground is covered with various\n"
              "leaves and dead things. Creepy screaming echoes around the graveyard.\n";
}
