inherit "room/room";

reset(status arg) 
{
  if(arg) return;

  add_exit("inn", "/world/city/inn");
add_exit("area1", "/wizards/arylith/area_project/portal");
  add_exit("cs",  "/world/city/cs");

  short_desc = "Shortdesc";
  long_desc =   
 "Arylith's workroom. \n"+
 "There's a small window opened slightly. \n"+
 "A small desk is in the middle of the room and a laptop, \n"+
 "which is used for gameplay and coding. \n"+
 "A note on the wall is labeled as /AREA_OHJEET & 'man'. \n"+
 "Enjoy your stay or leave.\n";

  property = allocate(1);
  property[0] = "no_summon";
  set_light(3);
}
