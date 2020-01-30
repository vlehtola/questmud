inherit "room/room";
reset(arg) {
        if(arg) return;
        short_desc = "A shady shore";
        long_desc = "This is a shady shore surroundered by dyind trees and runt undergrowth.\n"+
                    "A boat is tied with a loose knot to a huge tree that seems to be the\n"+
                    "only tree here still growing. In the boat is an old, very sleepy looking\n"+
                    "goblin dressed in rags and he is chained to the boat with a sturdy chain.\n";
        add_exit("northeast", "room19");
        add_exit("southeast", "room17");
        items = allocate(6);
        items[0] = "boat";
        items[1] = "This boat seems to have seen its best days";
        items[2] = "tree";
        items[3] = "One of the branches is a roped tied thigthly";
        items[4] = "rope";
        items[5] = "A rope tied one of the branches";
        }
        init() {
			 ::init();
add_action("enter", "enter");
}

enter(str) {
	if(str == "boat") {
		write("You step on the boat and give it a little push.\n");
		say(this_player()->query_name()+" steps on the boat.\n");
		move_object(this_player(), "/wizards/neophyte/village/boat");
		command("look",this_player());
		return 1;
	}
write("Enter where?\n");
return 1;
}


