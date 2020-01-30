
inherit "room/room";

reset(status arg) {
  if(arg) return;
  add_exit("inn","/world/city/inn");
  add_exit("cs","/world/city/cs");
  short_desc = "Huone";
  long_desc = "This is the room.\n"; 
  property = allocate(1);
  property[0] = "no_summon";
  set_light(3);
}




