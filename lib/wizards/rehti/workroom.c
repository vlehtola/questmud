inherit "room/room";

reset(status arg) {
  if(arg) return;
  add_exit("inn","/world/city/inn");
  add_exit("cs","/world/city/cs");
  add_exit("down","/wizards/rehti/dormund/entrance");
  short_desc = "shotdesc";
  long_desc = "long desc.\n"; 
  property = allocate(1);
  property[0] = "no_summon";
  set_light(3);
}







