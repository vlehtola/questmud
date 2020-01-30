inherit "room/room";
object monster;

reset(arg) {
  if(!present("zombie 2")) { 
    move_object(clone_object("/wizards/irmeli/area3/zombie.c"),
    this_object());
    move_object(clone_object("/wizards/irmeli/area3/zombie.c"),
    this_object());
}  

  if(arg) return;

  add_exit("east","/wizards/irmeli/area3/ruum31.c");
  add_exit("north","/wizards/irmeli/area3/ruum29.c");
 
  short_desc = "Small sand path in the graveyard";
  long_desc = "You are walking on the small sand path which is leading to the centre of the\n"+
                "graveyard. There are some gravestones next to the path. The misty wind is\n"+
                "blowing from the north. If you look exactly ahead you can notice some\n"+   
                "movement in the shadows. Creepy screaming echoes around the graveyard.\n";
}

