inherit "room/room";
object monster, monster2;

reset(arg) {
        if(!monster) {
                monster = clone_object("/wizards/rag/ruins/mon/dust");
                move_object(monster,this_object());
        }
        if(!monster2) {
                monster2 = clone_object("/wizards/rag/ruins/mon/gdemon");
                move_object(monster2,this_object());
        }
        if(arg) return;
        add_exit("north","/wizards/rag/ruins/dust2");
        add_exit("west","/wizards/rag/ruins/junction");
        add_exit("southeast","/wizards/rag/ruins/dust3");

        short_desc = "In a dusty tunnel";
	long_desc =	"This tunnel has been recently dug. There are rocks and dust everywhere.\n"+
			"It seems that the tunnel has been dug in a hurry and without the need\n"+
			"for beauty. The walls are rough and there are some planks here keeping\n"+
			"the ceiling up.\n";

        set_not_out(1);
}

chant(str) {
        if(str == "ventus") {
        tell_room(this_object(),"A gush of wind blows some of the dust away.\n");
        return 1;
        }
}
        
