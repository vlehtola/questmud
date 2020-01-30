inherit "room/room";

reset(arg) {
  if(arg) return;
  short_desc = "An underground tunnel";
  long_desc = "The tunnel seems to been here forever. There are no traces that any\n"+
	      "humanoid creatures would have carved it. It must have been done by\n"+
	      "the nature. The tunnel is short and it's ends can be seem on both\n"+
	      "directions.\n";
  call_other("/wizards/celtron/field/virtual_map", "loads_the_map");
  add_exit("west", "/wizards/celtron/field/virtual_map: 37 15");
  add_exit("east", "out: 113 110");
}
