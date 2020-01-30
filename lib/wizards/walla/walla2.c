inherit "room/room";

reset(arg) {

  add_exit("east","walla1");
  short_desc = "You shouldn't be here.";
  long_desc = "hc descit in da house!";

 }
joku_tuli(string str) {
	write(str+"\n");
	tell_object(find_player(lower_case(str)),"Tulit");
	shout("Testing testing ("+str+")\n");
	return 1;
}
