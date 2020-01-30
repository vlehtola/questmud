inherit "room/room";
object monster;

reset(arg) {
  if(!present("ghost")) { 
    move_object(clone_object("/wizards/irmeli/area3/ghost.c"),
    this_object());
}  

  if(arg) return;

  add_exit("south","/wizards/irmeli/area3/ruum10.c");
  add_exit("north","/wizards/irmeli/area3/ruum8.c");
 
  short_desc = "Small sand path in the graveyard";
  long_desc = "You are walking on the small sand path which is leading to the centre of the\n"+
                "graveyard. There are some gravestones next to the path. The misty wind is\n"+
                "blowing from the north. If you look exactly ahead you can notice some\n"+   
                "movement in the shadows. Creepy screaming echoes around the graveyard.\n";
}


