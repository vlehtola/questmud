inherit "room/room";
inherit "room/door";

int door_number;

reset(arg) {
  if (arg) { return; }
  short_desc = "Door room";
  long_desc = "You are in the door room.\n";
  door_reset();
  door_number = 1;
  set_door_label("wooden door", door_number);
  set_door_dir("east", "/wizards/belar/ent/rooms/l1hut.c", door_number);
  set_door_link("/wizards/belar/tree.c", door_number);
  set_door_code(66, door_number);
  set_locked(1, door_number);
}

init(){
	::init();
	door_init();
	add_action("kick_door","kick");
}

status kick_door(string str){
	if(!str || str != "door"){
	write("kick what?\n");
	return 1;
	}
if(this_player()->query_str() > 200) {
	write("You kick the door and it opens!\n");
	say(this_player()->query_name()+"kicks the door and it opens.\n");
	add_exit("crack","/wizards/belar/ent/rooms/l1hut.c");
	return 1;
}
write("You kick the door.");
return 1;
}
