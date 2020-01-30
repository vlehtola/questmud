inherit "room/room";
object monster;

init() {
	add_action("up","up");
	::init();
}

reset(arg) {
        if(!monster) {
                monster = clone_object("/wizards/rag/ruins/mon/dark");
                move_object(monster,this_object());
        }
        if(arg) return;
        add_exit("north","/wizards/rag/ruins/junction");
        add_exit("west","/wizards/rag/ruins/junction");
        add_exit("east","/wizards/rag/ruins/junction");
        add_exit("south","/wizards/rag/ruins/junction");

        short_desc = "A dark tunnel";
	long_desc =	"This is a dark tunnel. The darkness is overwhelming. You can't see\n"+
			"anything, you can't event feel anything. The ground seems to be solid\n"+
			"stone. Some corridors lead to all directions, but you have no idea\n"+
			"where to go.\n";

	set_not_out(1);
}

chant(str) {
	if(str == "lux") {
	tell_room(this_object(),"The scroll flashes brightly and for just a moment you see a stairway leading up.\n");
	return 1;
	}
}

up() {
	this_player()->move_player("up#/wizards/rag/ruins/dark6");
	return 1;
}
