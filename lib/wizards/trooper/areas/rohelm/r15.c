inherit "room/room";

reset(arg) {
  add_exit("north","/wizards/trooper/areas/rohelm/r27.c");
  add_exit("east","/wizards/trooper/areas/rohelm/r16.c");
  add_exit("south","/wizards/trooper/areas/rohelm/r3.c");
  add_exit("west","/wizards/trooper/areas/rohelm/r14.c");


  short_desc = "The main street in the city of Rohelm.";
  long_desc = "The main street is covered with cobblestones. A lot of various stuff\n"+
              "is abandoned on the streets causing a mess. The buildings look dark\n"+
    	      "and abandoned. Some walls of the buildings are collapsed revealing an\n"+
	      "unwelcome sight of bodies and destruction. There's no greeness of nature\n"+
	      "at all in this city, just pure colours of destruction.\n";

  items = allocate(6);
  items[0] = "walls";
  items[1] = "There's some writing at some walls";
  items[2] = "cobblestones";
  items[3] = "Most cobblestones are covered with green slime";
  items[4] = "writing";
  items[5] = "it reads: Beware of twilight";
}