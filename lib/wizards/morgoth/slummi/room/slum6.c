inherit "room/room";
object monster;
 
reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/morgoth/slummi/npc/dog");
    move_object(monster, this_object());
  }
  if(arg) return;
 
  add_exit("west","/wizards/morgoth/slummi/room/slum5");
  add_exit("northeast","/wizards/morgoth/slummi/room/slum7");
  short_desc = "A filthy street.";
  long_desc = "You are in a long, dark street which runs west and now it is\n"+
              "turning to the northeast. The darkness only makes this smelly\n"+
              "street worse. There is nothing worse than hearing sounds like\n"+
              "footsteps creeping up on you in the dark.\n";
 }
