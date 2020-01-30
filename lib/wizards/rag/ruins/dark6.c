inherit "room/room";
object monster;

int chest_open;
int cross_taken;

init() {
	add_action("open","open");
	add_action("close","close");
	add_action("look","look");
	add_action("take","take");
	add_action("take","get");
	::init();
}

reset(arg) {
        if(!monster) {
                monster = clone_object("/wizards/rag/ruins/mon/lich");
                move_object(monster,this_object());
        }
        if(arg) return;
	chest_open = 0;
	cross_taken = 0;

        add_exit("down","/wizards/rag/ruins/dark5");

        short_desc = "A dark chamber";
	long_desc = 	"This is a dark chamber. It seems to be some kind of a workroom.\n"+
			"A wooden desk is located in the northern wall. There are some\n"+
			"evil-looking instruments on a cabinet which is placed next to the\n"+
			"desk. Some candles are burning on the desk. You spot a few books\n"+
			"on the desk, but you can't really understand them. There is an\n"+
			"oaken chest in the corner.\n";

	items = allocate(4);
	items[0] = "instruments";
	items[1] = "There instruments are perhaps used in torturing";
	items[2] = "books";
	items[3] = "You get a really bad feeling about these books";

	set_light(1);
	set_not_out(1);
}

open(str) {
	if(str == "chest" && !chest_open) {
		write("You open the chest.\n");
		say(this_player()->query_name()+" opens the chest.\n");
		chest_open = 1;
		return 1;
	} else if(str == "chest" && chest_open) {
		write("The chest is already open.\n");
		return 1;
	} else {
		write("Open what?\n");
		return 1;
	}
}

close(str) {
        if(str == "chest" && chest_open) {
                write("You close the chest.\n");
                say(this_player()->query_name()+" closes the chest.\n");
                chest_open = 0;   
                return 1;
        } else if(str == "chest" && !chest_open) {
                write("The chest is already closed.\n");
                return 1;
        } else {
                write("Close what?\n");
                return 1;
        }
}


look(str) {
	if(str == "at chest") {
		if(!chest_open) {
			write("A sturdy chest made from oak. It is closed.\n");
			return 1;
		}
		if(cross_taken) {
			write("A sturdy chest made from oak. It is open.\n");
			return 1;
		}
		write("A sturdy chest made from oak. It is open.\n"+
			"There is a golden cross in the chest.\n");
		return 1;
		}
}
			
take(str) {
	if(chest_open && !cross_taken && (str == "cross" || str == "cross from chest")) {
		write("You take the cross from the chest.\n");
		say(this_player()->query_name()+" takes the cross from the chest.\n");
		move_object(clone_object("/wizards/rag/ruins/obj/cross"),this_player());
		cross_taken = 1;
		return 1;
	} else if(!chest_open && str == "cross from chest") {
		write("But the chest is closed.\n");
		return 1;
	}
}
