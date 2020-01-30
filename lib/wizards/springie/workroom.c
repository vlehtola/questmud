inherit "room/room";
reset(status arg) {
  if(arg) return;
  add_exit("inn","/world/city/inn");
  add_exit("cs","/world/city/cs");
  short_desc = "Springie's workroom";
  long_desc = "This is the workroom of the newbie coder Springie.\n";
  property = allocate(1);
  property[0] = "no_summon";
  set_light(3);
}
