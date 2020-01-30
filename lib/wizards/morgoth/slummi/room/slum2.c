inherit "room/room";
object monster;
 
reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/morgoth/slummi/npc/beggar");
    move_object(monster, this_object());
  }
  if(arg) return;
 
  add_exit("west","/wizards/morgoth/slummi/room/slum1");
  add_exit("east","/wizards/morgoth/slummi/room/slum3");
  add_exit("south","/wizards/celtron/headhunter_quest/room");
  short_desc = "A filthy street.";
  long_desc = "You are in a long, dark street which runs west and east.\n"+
              "The darkness only makes this smelly street worse. There is\n"+
              "nothing worse than hearing sounds like footsteps creeping\n"+
              "up on you in the dark.\n";
}
