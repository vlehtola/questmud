inherit "room/room";
reset(arg)  {
add_exit("tomb", "/wizards/aarrgh/nyxi/mist2");
add_exit("east", "/wizards/aarrgh/nyxi/gates");
short_desc = "In the graveyard";
long_desc = "A small graveyard has been built here. This place is surrounded with mist and\n"
	    "the mist is thick, very thick. A tomb in the center of graveyard can hardly be\n"
            "noticed. The tomb is large enough to fit one tombstone inside.\n";
set_light(1);

items = allocate(4);
  items[0] = "mist";
  items[1] = "The mist is thick, thick enough to slow you down";



}
