inherit "room/room";
int i;
reset(arg) {
	i = 0;
        if(arg) return;
        short_desc = "A large clearing";
        long_desc = "A large clearing where isn't any sign of anything living,\n"
                    "there aren't any trees and the undergrowth has also disappeard.\n"
                    "Just a big windmill that is used to propel water from the lake to the fields,\n"
                    "this is a quite windy place and as this so close to the lake,\n";
        add_exit("north", "room13");
        add_exit("northwest", "room19");
        add_exit("southwest", "room17");
        add_exit("southeast", "entrance");
        items = allocate(2);
        items[0] = "windmill";
        items[1] = "The windmill looks abandoned";
        }

search_finished(str) {
	object key;
	if(i == 0 && str == "windmill") {
		write("You have entrance to windmill!\n");
		say(this_player()->query_name()+ " founds something.\n");
		add_exit("windmill", "windmill");
		i = 1;
		return 1;
	}
	write("You find nothing special.\n");
	say(this_player()->query_name()+ " founds nothing.\n");
	return 1;
}