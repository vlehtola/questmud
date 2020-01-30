inherit "room/room";  

reset(arg) {
if(!present("ghost")) { 
    move_object(clone_object("/wizards/devil/area/mobit/ghost.c"), this_object());
    move_object(clone_object("/wizards/devil/area/mobit/ghost.c"), this_object());
}
  add_exit("east","/wizards/devil/area/huoneet/r24.c");
  add_exit("southwest","/wizards/devil/area/huoneet/r22.c");

  short_desc = "Small sand path in the graveyard";
  long_desc = "You are walking on the small sand path which is leading to the centre of the\n"+
                "graveyard. You feel awful by walking on this creepy path. The misty wind is\n"+
                "blowing from somewhere. If you look straight ahead you can notice some\n"+   
                "movement in the shadows. Creepy screaming echoes around the graveyard.\n";
}
