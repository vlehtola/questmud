inherit "room/room";
object monster;

reset(arg) {
        if(!monster) {
                monster = clone_object("/wizards/rag/ruins/mon/gdemon");
                move_object(monster,this_object());
        }
        if(arg) return;
        add_exit("north","/wizards/rag/ruins/dark1");
        add_exit("west","/wizards/rag/ruins/tunnel1");
	add_exit("east","/wizards/rag/ruins/dust1");
        add_exit("south","/wizards/rag/ruins/burn1");
        add_exit("portal","/wizards/rag/ruins/church3");

        short_desc = "Junction of dark tunnels";
        long_desc =     "This is a small chamber connecting many dark tunnels. Darkness seems\n"+
                        "to be flowing from north. Hot air is coming from south. A massive corridor\n"+
                        "cut from solid stone is leading west. There is dust and sand next to the\n"+
			"tunnel leading east. A blood-red portal stands in the middle of the room.\n"+
			"Tormented screams are echoing in the corridors.\n";

        items = allocate(2);
        items[0] = "portal";
        items[1] = "The portal seems to be the same that the one you entered in the church";

        set_not_out(1);
}
