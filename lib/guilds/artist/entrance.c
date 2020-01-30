inherit "room/room";

reset(arg) {
  if(arg) return;
     add_exit("hut","/guilds/artist/school");
  add_exit("south","out: 45 72");
  add_exit("north","out: 45 72");
  add_exit("east","out: 45 72");
  add_exit("west","out: 45 72");
  short_desc = "An opening";
  long_desc = "A peaceful opening in the middle of a light forest.\n"+
	      "There is a hut near a big oak. Birds are singing quietly.\n";
}
