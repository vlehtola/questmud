inherit "room/room";

reset(arg) {
  if(arg) return;
  add_exit("room2","/wizards/luminarc/room2");
  add_exit("inn","/world/city/inn");
  add_exit("cs","/world/city/cs");
  add_exit("castle","/wizards/luminarc/wizcastle/room0");
short_desc = "Luminarc's Workroom";
  long_desc = "You are standing on luminarc's workroom. this place is very clean and well desinged..\n"; 
  property = allocate(1);
  property[0] = "no_summon";
  set_light(3);
}







