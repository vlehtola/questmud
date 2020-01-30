inherit "room/room";
object monster;
 
reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/morgoth/slummi/npc/beggar");
    move_object(monster, this_object());
  }
  if(arg) return;
 
  add_exit("north","/world/city/silcop4");
  add_exit("south","/wizards/morgoth/slummi/room/slum9");
  short_desc = "End of a filthy street";
  long_desc = "You are standing at the end of a filthy street.\n"+
              "To the north of you are the better parts of the city.\n";
  }
