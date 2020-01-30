inherit "room/room";
object monster,monster2;

reset(arg) {
  if(!present("zombie")) { 
    move_object(clone_object("/wizards/devil/area/mobit/zombie.c"), this_object());
    move_object(clone_object("/wizards/devil/area/mobit/zombie.c"), this_object());
}  

  if(arg) return;

  add_exit("southeast","/wizards/devil/area/huoneet/r29.c");
  add_exit("west","/wizards/devil/area/huoneet/r27.c");

  short_desc = "Small sand path in the graveyard";
  long_desc = "You are walking on the small sand path which is leading to the centre of the\n"+
                "graveyard. You feel awful by walking on this creepy path. The misty wind is\n"+
                "blowing from somewhere. If you look straight ahead you can notice some\n"+   
                "movement in the shadows. Creepy screaming echoes around the graveyard.\n";
}
