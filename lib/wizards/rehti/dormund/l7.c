inherit "room/room";
object monster;

reset(arg) {
  add_exit("north","/wizards/rehti/dormund/l6");  
  add_exit("east","/wizards/rehti/dormund/l8"); 
  add_exit("up","/wizards/rehti/dormund/lt1");  
  short_desc = "Below southwest scout tower.";
  long_desc = "This is one of the high towers used for scouting purposes. It seems that these knights trust their scouts.\n"+
              "It is made sure that no one bother's their work and that's why these towers seems so well protected.\n"+
              "Other three towers can be seen in north, northeast and east. Also everything that happens in inner city can\n"+
              "be seen from here so that guards can see any events from here without leaving their post.\n";
  if(!present("knight")) {
  move_object(clone_object("/wizards/rehti/dormund/monsut/blockguard"), this_object());
  if(arg) { return; }
}
}