inherit "room/room";

reset(arg) {
  if(arg) return;
  add_exit("south","/wizards/torspo/workroom");
  add_exit("gnomes","/wizards/torspo/areat/gnomes/entrance.c");
  add_exit("ogres","/wizards/torspo/areat/ogre/room1.c");
  short_desc = "Wizroom";
  long_desc = "Portal.\n"; 
  property = allocate(1);
  property[0] = "no_summon";
}
