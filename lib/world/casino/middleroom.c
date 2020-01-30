inherit "room/room";

reset(arg) {
  if(arg) return;
  short_desc = "The casino";
  add_exit("north", "/world/casino/machineroom");
  add_exit("south", "/daemons/lotto");
  add_exit("east","/wizards/rag/misc/blackjack");
  long_desc = "The casino's middle room is full of smoke and people.\n"+
	"All playrooms are connected here. The exit is to the west.\n";
  add_exit("west", "/world/city/gold8");
}
