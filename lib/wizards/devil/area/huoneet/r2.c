inherit "room/room";
object monster,monster2;

reset(arg) {
  if(!present("ghost")) { 
    move_object(clone_object("/wizards/devil/area/mobit/ghost.c"), this_object());
    move_object(clone_object("/wizards/devil/area/mobit/ghost.c"), this_object());
}  

  if(arg) return;

  add_exit("north","/wizards/devil/area/huoneet/r3.c");
  add_exit("out","/wizards/devil/area/huoneet/r1.c");
  set_light(2);
  short_desc = "Small sand path in the graveyard";
  long_desc = "You are walking on the small sand path which is leading to the centre of the\n"+
                "of the graveyard. Some fireflies fly about here, softly lighting the\n"+
                "surroundings. The misty wind blowing from somewhere\n"+
                "If you look straight ahead you can notice some movement in the shadows. \n"+   
                "Creepy screaming echoes around the graveyard.\n";
}

