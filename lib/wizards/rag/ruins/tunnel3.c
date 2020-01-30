inherit "room/room";
object monster, shelter;

reset(arg) {
        if(!monster) {
                monster = clone_object("/wizards/rag/ruins/mon/gdemon");
                move_object(monster,this_object());
        }
        if(arg) return;
	add_exit("north","/wizards/rag/ruins/tunnel3n");
        add_exit("east","/wizards/rag/ruins/tunnel2");
	add_exit("south","/wizards/rag/ruins/tunnel3s");

        short_desc = "In a massive tunnel";
	long_desc =	"This tunnel is very massive. It is made of large symmetrical white rocks.\n"+
			"The ground also consists of the same rocks. The tunnel ends here. There are\n"+
			"some chambers in the north and the south. Some torches are burning on the\n"+
			"walls.\n";

        set_not_out(1);
	set_light(3);
}

add() {
	tell_room(this_object(),"The Paladin raises his sword high and shouts: 'Reveal youself,"
				+" creature of darkness!'\n");
	tell_room(this_object(),"Suddenly a doorway opens, leading west. You hear an eerie voice in you head:\n");
	tell_room(this_object(),"'Welcome to your doom! Your pathetic paladin is no match for my magicks!'\n");
	add_exit("west","/wizards/rag/ruins/tunnel4");
	call_other("/wizards/rag/ruins/tunnel4","add");
	tell_room(this_object(),"The Paladin says: 'Hurry, the doorway won't last long!'\n");
	return 1;
}

rem() {
	call_other("/wizards/rag/ruins/tunnel4","rem");
	remove_exit("west");
	tell_room(this_object(),"Suddenly the doorway closes and only a wall remains.\n");
	return 1;
}