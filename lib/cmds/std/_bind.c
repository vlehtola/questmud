cmd_bind(string str) {
  string loc;
  object room;

  room = environment(this_player());
  if(room->query_startroom()) {
    loc = file_name(room);
    this_player()->set_starting_location(loc);
    write("You bind this place as your starting location.\n");
    return 1;
  }
  write("You cannot bind to this location.\n");
  loc = this_player()->query_starting_location();
  if(!loc || loc == "/world/city/inn") {
	write("Your starting location is the Inn of Duranghom.\n");
	return 1;
  }
  write("Your starting location is "+loc->short()+".\n");
  return 1;
}
