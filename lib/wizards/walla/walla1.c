inherit "room/room";

reset(arg) {

  add_exit("west","walla2");
  short_desc = "You shouldn't be here.";
  long_desc = "hc descit in da house!";
 }

init() {
	::init();
	add_action("west","west");
}

west() {
	call_other("/wizards/siki/walla2","joku_tuli",this_player()->query_name());
}
