inherit "room/room";
object monster;

reset(arg) {
  add_exit("west","/wizards/rehti/dormund/r1");  
  add_exit("south","/wizards/rehti/dormund/r3");
  add_exit("up","/wizards/rehti/dormund/rt3");  
  short_desc = "Below northeast scout tower.";
  long_desc = "This is one of the high towers used for scouting purposes. It seems that these knights trust their scouts.\n"+
              "It is made sure that no one bother's their work and that's why these towers seems so well protected.\n"+
              "Other three towers can be seen in west, southwest and south. Also everything that happens in inner city can\n"+
              "be seen from here so that guards can see any events from here without leaving their post.\n";
  if(!present("knight")) {
  move_object(clone_object("/wizards/rehti/dormund/monsut/blockguard"), this_object());
  if(arg) { return; }
}  
}