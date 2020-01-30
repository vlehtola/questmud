inherit "room/room";
object monster, shelter;

reset(arg) {
        if(!monster) {
                monster = clone_object("/wizards/rag/ruins/mon/gdemon");
                move_object(monster,this_object());
        }
        if(arg) return;
	add_exit("north","/wizards/rag/ruins/tunnel2n");
	add_exit("west","/wizards/rag/ruins/tunnel3");
        add_exit("east","/wizards/rag/ruins/tunnel1");
	add_exit("south","/wizards/rag/ruins/tunnel2s");

        short_desc = "In a massive tunnel";
	long_desc =	"This tunnel is very massive. It is made of large symmetrical white rocks.\n"+
			"The ground also consists of the same rocks. The tunnel seems to continue\n"+
			"far to the west. There are some chambers in the north and the south. Some\n"+
			"torches are burning on the walls.\n";

        set_not_out(1);
	set_light(3);
}