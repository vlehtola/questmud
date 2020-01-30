inherit "room/room";
object goblin;

reset(arg) {
        if(!goblin) {
                goblin = clone_object("/wizards/neophyte/village/monst/goblinreclude");
                move_object(goblin, this_object());
        }
        if(arg) return;
        short_desc = "A small and dark hut";
        long_desc = "This is a small hut built on a ferry that floats in this lake.\n"+
                    "The floor is extremely wobbly and because of that, the few \n"+
                    "furniture that are in here are nailed to the floor. A cold breeze\n"+
                    "is coming from the hole that probably has used to be a window, but\n"+
                    "has been broken for some reason. A fireplace is placed in the middle\n"+
                    "of the room, but there is no wood in it, and there is no sign that it\n"+
                    "has been ever lit. Two chairs are front of the fireplace.\n";
        set_not_out(1);
        set_light(1);
            items = allocate(6);
		            items[0] = "fireplace";
		            items[1] = "This fireplace looks old but so new, it looks like there arent been a light ever";
		            items[2] = "chairs";
		            items[3] = "A round wooden chair";
		            items[4] = "hole";
                    items[5] = "Looks like there have been a window in long time ago and from the hole you can see lots of water";
property = allocate(1);
property[0] = "no_summon";

        }
        init() {
			::init();
			add_action("dive", "north");
			add_action("dive", "south");
			add_action("dive", "west");
			add_action("dive", "east");
			add_action("dive", "northwest");
			add_action("dive", "northeast");
			add_action("dive", "southeast");
			add_action("dive", "southwest");
}
dive() {
	int i;
	i = this_player()->query_max_hp();
	write("You jump in the hole and dive deep in water.\n");
	say(this_player()->query_name()+" dives in the hole.\n");
	this_player()->reduce_hp(random(i*3));
	if(!this_player()->query_ghost()) {
		move_object(this_player(), "/wizards/neophyte/village/room18");
		return 1;
	}
}
