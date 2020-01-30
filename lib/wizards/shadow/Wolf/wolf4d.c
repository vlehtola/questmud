inherit "room/room";

object monster,monster2;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/shadow/Wolf/monsters/iceguard");
    move_object(monster, this_object());
  }
  if(arg) return;
  if(!monster2) {
    monster2 = clone_object("/wizards/shadow/Wolf/monsters/iceguard");
    move_object(monster2, this_object());
  }
  add_exit("enter","/wizards/shadow/Wolf/wolfking");
  add_exit("west","/wizards/shadow/Wolf/wolf4c");
  short_desc = "In a huge room carved in solid ice";
  long_desc =
  "You have arrived into a big room carved in solid ice. This room is\n"+
  "full of statues that look like wolves, and on the walls there are carved\n"+
  "wolfprints. At the end of the room there are two large walls made from\n"+
  "some black material, as you look at them closer you notice that the\n"+ 
  "material is ice. Big torches light the room, but the ice does not melt\n"+
  "despite the warmth. A big grinning wolf's head has been placed in the\n"+
  "upper part of the room.\n";
}
