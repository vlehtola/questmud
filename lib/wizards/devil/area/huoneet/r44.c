inherit "room/room";
object monster,monster2;

reset(arg) {
  if(!present("spirit")) { 
    move_object(clone_object("/wizards/devil/area/mobit/spirit.c"), this_object());
    move_object(clone_object("/wizards/devil/area/mobit/spirit.c"), this_object());
}  

  if(arg) return;

  add_exit("southwest","/wizards/devil/area/huoneet/r45.c");
  add_exit("east","/wizards/devil/area/huoneet/r43.c");
 set_light(2);
  short_desc = "Small sand path in the graveyard";
  long_desc = "You are walking on the small sand path which is leading to the centre of the\n"+
              "graveyard. Some fireflies fly about here, softly lighting the surroundings.\n"+
              "You can notice some red and scary looking eyes gazing at you behind the\n"+
              "gravestones. There is few foot steps on the ground. If you look straight ahead\n"+   
              "you can notice some movement in the shadows. Creepy screaming echoes around\n"+
              "the graveyard.\n";
}