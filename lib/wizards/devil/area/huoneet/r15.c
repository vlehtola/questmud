inherit "room/room";
object monster,monster2;

reset(arg) {
  if(!present("ghost")) { 
    move_object(clone_object("/wizards/devil/area/mobit/ghost.c"), this_object());
    move_object(clone_object("/wizards/devil/area/mobit/ghost.c"), this_object());
}  

  if(arg) return;

  add_exit("north","/wizards/devil/area/huoneet/r16.c");
  add_exit("east","/wizards/devil/area/huoneet/r14.c");
 set_light(2);
  short_desc = "Small sand path in the graveyard";
  long_desc = "You are walking on the small sand path which is leading to the centre of the\n"+
              "graveyard. Some fireflies fly about here, softly lighting the surroundings.\n"+
              "The misty wind is blowing some wood leaves in here. If you look straight ahead\n"+   
              "you can notice some movement in the shadows. The ground is covered with various\n"
              "leaves and dead things. Creepy screaming echoes around the graveyard.\n";
}
