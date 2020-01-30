inherit "room/room";  

reset(arg) {
  add_exit("north","/wizards/devil/area/huoneet/r4.c");
  add_exit("south","/wizards/devil/area/huoneet/r2.c");
  if(!present("man")) { 
  move_object(clone_object("/wizards/devil/area/mobit/man.c"), this_object());}
  short_desc = "Small sand path in the graveyard";
  long_desc = "You are walking on the small sand path which is leading to the centre of the\n"+
                "graveyard. You feel awful while walking on this creepy path. The misty wind is\n"+
                "blowing from somewhere. If you look straight ahead you can notice some\n"+   
                "movement in the shadows. Creepy screaming echoes around the graveyard.\n";
}
