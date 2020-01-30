status in_sea;
init() {
  add_action("enter_boat", "enter");
  add_action("out_boat", "out");
}

enter_boat() {
	if(!present("boat", environment(this_player()))) { return 1; }
	write("You step on the boat.\n");
	say(this_player()->query_name()+" enters the boat.\n");
	move_object(this_player(), this_object());
	return 1;
}
out_boat() {
	if(present("boat", environment(this_player()))) { return; }
	if(in_sea) { write("Jumping in the ocean would be suicide so you decide to withdraw your attempt.\n"); return 1; }
    write("You step out the boat.\n");
    move_object(this_player(), environment(this_object()));
    say(this_player()->query_name()+ " steps out from the boat.\n");
    return 1;
}

short() {
  return "A small fishing boat";

}

id(str) {
  return str == "boat";
}

long() {
  write("You are standing in the deck of small fishing boat, the deck\n"+
        "seems to be slippery. A captain is moving the rudder and\n"+
        "giving orders to the men that are rowing the boat.\n");
}

drop() {
  return 1;
}
get() {
  return 0;
}

move_island() {
	move_object(this_object(), "/wizards/duncan/island/entrance");
	tell_room(this_object(), "The boat arrives to pier.\n");
	tell_room(environment(this_object()), "A small boat arrives from sea.\n");
	call_out("move_back", 120);
	call_out("move1", 60);
	in_sea = 0;
return 1;
}
move_back() {
	move_object(this_object(), "/wizards/duncan/island/pier");
	tell_room(this_object(), "The boat arrives to pier.\n");
	tell_room(environment(this_object()), "A small boat arrives from sea.\n");
	call_out("move_island", 120);
	call_out("move1", 60);
	in_sea = 0;
	return 1;
}

move1() {
	tell_room(environment(this_object()), "The boat leaves from the pier.\n");
	move_object(this_object(), "/wizards/duncan/island/temp");
	in_sea = 1;
	tell_room(this_object(), "The boat moves a little.\n");
	return 1;
}