inherit "room/room";  

reset(arg) {
  add_exit("north","/wizards/devil/area/huoneet/r32.c");
  add_exit("south","/wizards/devil/area/huoneet/r30.c");
 set_light(2);
  short_desc = "Small sand path in the graveyard";
  long_desc = "You are walking on the small sand path which is leading to the centre of the\n"+
              "graveyard. Some fireflies fly about here, softly lighting the surroundings.\n"+
              "The misty wind is blowing some wood leaves in here. If you look straight ahead\n"+   
              "you can notice some movement in the shadows. There are some footsteps on the\n"+
              "ground, like someone had walked in here short time ago. Creepy screaming echoes\n"+ 
              "around the graveyard.\n";
}
