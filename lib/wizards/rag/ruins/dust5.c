inherit "room/room";
object monster, monster2;
int pulled;

init() {
	add_action("pull","pull");
	::init();
}

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
        add_exit("southwest","/wizards/rag/ruins/dust4");

        short_desc = "In a dusty tunnel";
	long_desc =	"This tunnel has been recently dug. There are rocks and dust everywhere.\n"+
			"It seems that the tunnel has been dug in a hurry and without the need\n"+
			"for beauty. The walls are rough and there are some planks here keeping\n"+
			"the ceiling up. There is an unusually large pile of dust on the ground.\n";

	items = allocate(4);
	items[0] = "dust";
	items[1] = "It is a very large pile of dust";
	items[2] = "pile";
	items[3] = items[1];

        set_not_out(1);
	pulled = 0;
}

chant(str) {
        if(str == "ventus" && !present("lever")) {
        tell_room(this_object(),"A gush of wind blows the big pile dust away revealing a lever.\n");
	tell_room(this_object(),"Some dust fall from the walls and the ceiling.\n");
	move_object(clone_object("/wizards/rag/ruins/obj/lever"),this_object());
        return 1;
        }
	if(str == "ventus") {
	tell_room(this_object(),"A gush of wind blows the big pile dust away.\n");
	return 1;
	}
}
        
pull(str) {
	if((str == "lever" && !present("lever")) || str != "lever") {
		write("Pull what?\n");
		return 1;
	}
	if(!pulled) {
	  write("You pull the lever and feel something magical happening.\n");
	  say(this_player()->query_name()+" pulls the lever and you feel something magical happening.\n");
	  call_other("/wizards/rag/ruins/tunnel1","remove");
	  pulled = 1;
	  return 1;
	}
	if(pulled) {
	  write("The lever is jammed.\n");
	  say(this_player()->query_name()+" tries to pull the lever but it is jammed.\n");
	  return 1;
	}
}
