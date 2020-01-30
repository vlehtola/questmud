inherit "room/room";

reset(arg) {
  if(arg) return;
  add_exit("inn","/world/city/inn");
  add_exit("cs","/world/city/cs");
  add_exit("castle","/wizards/luminarc/wizcastle/room0");
  add_exit("mountain","/wizards/luminarc/mountain/entrance");
  short_desc = "Hell";
  long_desc = "You are in hell.\n"; 
  property = allocate(1);
  property[0] = "no_summon";
  set_light(3);
}







