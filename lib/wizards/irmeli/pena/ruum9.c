inherit "room/room";
object monster;

reset(arg) {

  if(arg) return;

  add_exit("south","/wizards/irmeli/pena/ruum11.c");
  add_exit("up","/wizards/irmeli/pena/ruum8.c");
  set_not_out(1);

  short_desc = "Small corridor in Valley of Angels";
  long_desc = "You are standing in a small corridor. This corridor is probably made\n"+
                "thousands years ago. This place was prison or graveyard for the\n"+
                "enemies of the angels.\n";
}


