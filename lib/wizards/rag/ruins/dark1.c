inherit "room/room";
object monster;

reset(arg) {
        if(!monster) {
                monster = clone_object("/wizards/rag/ruins/mon/dark");
                move_object(monster,this_object());
        }
        if(arg) return;
        add_exit("north","/wizards/rag/ruins/dark2");
        add_exit("west","/wizards/rag/ruins/dark2");
        add_exit("east","/wizards/rag/ruins/dark2");
        add_exit("south","/wizards/rag/ruins/dark2");

        short_desc = "A dark tunnel";
	long_desc =	"This is a dark tunnel. The darkness is overwhelming. You can't see\n"+
			"anything, you can't event feel anything. The ground seems to be solid\n"+
			"stone. Some corridors lead to all directions, but you have no idea\n"+
			"where to go.\n";

	set_not_out(1);
}

chant(str) {
        if(str == "lux") {
        tell_room(this_object(),"The scroll flashes brightly in the darkness, but it reveals nothing.\n");
        return 1;
        }
}
	
