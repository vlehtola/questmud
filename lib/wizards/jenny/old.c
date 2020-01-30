inherit "room/room";

reset(status arg) {
  if(arg) return;
  add_exit("inn","/world/city/inn");
  add_exit("cs","/world/city/cs");
  add_exit("arrin","/wizards/nalle/workroom.c");
  short_desc = "Jenny's workroom";
  set_long("Jennyn oma lämmin huane!\n");
  property = allocate(1);
  property[0] = "no_summon";
  set_light(3);
}
