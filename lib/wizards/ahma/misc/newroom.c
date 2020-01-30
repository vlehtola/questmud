inherit "room/room";
object potion, mob;

reset(arg) {
if(arg) return;
  add_exit("west", "/wizards/ahma/workroom");
  add_exit("cs", "/world/city/cs");
  short_desc = "A room";
  long_desc = "This is a room.\nThere seems to be a picture on the wall.\n";
  items = allocate(2);
  items[0] = "picture";
  items[1] = "An ugly picture of some stange animal-like thing";
  property = allocate(2);
  property[0] = "no_summon";
  property[1] = "no_tele";
  set_not_out(1);
  set_light(0);
}
