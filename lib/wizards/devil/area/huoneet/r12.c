inherit "room/room";  

reset(arg) {
if(!present("ghost")) { 
    move_object(clone_object("/wizards/devil/area/mobit/ghost.c"), this_object());
    move_object(clone_object("/wizards/devil/area/mobit/ghost.c"), this_object());
}
  add_exit("west","/wizards/devil/area/huoneet/r13.c");
  add_exit("southwest","/wizards/devil/area/huoneet/r11.c");
 set_light(2);
  short_desc = "Small sand path in the graveyard";
  long_desc =   "You are walking on the small sand path which is leading to the centre of the\n"+
                "graveyard. Some fireflies fly about here, softly lighting the surroundings.\n"+
                "The misty wind is blowing from somewhere. If you look straight ahead you can \n"+                  "notice some movement in the shadows. Creepy screaming echoes around the\n"+ 
                "graveyard.\n";

}
