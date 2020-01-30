inherit "room/room";
object monster,monster2;

reset(arg) {
  if(!present("spirit")) { 
    move_object(clone_object("/wizards/devil/area/mobit/spirit.c"), this_object());
    move_object(clone_object("/wizards/devil/area/mobit/spirit.c"), this_object());
}  

  if(arg) return;

  add_exit("west","/wizards/devil/area/huoneet/r38.c");
  add_exit("south","/wizards/devil/area/huoneet/r36.c");
 set_light(2);
  short_desc = "Small sand path in the graveyard";
  long_desc = "You are walking on the small sand path which is leading to the centre of the\n"+
              "graveyard. Some fireflies fly about here, softly lighting the surroundings.\n"+
              "The misty wind is blowing from somewhere. If you look straight ahead you can\n"+   
              "notice some movement in the shadows. Creepy screaming echoes around the\n"+ 
              "graveyard.\n";
}
