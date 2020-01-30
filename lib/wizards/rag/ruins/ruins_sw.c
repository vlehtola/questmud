inherit "room/room";

init() {
        add_action("fill","fill");
	add_action("use","use");
        ::init();
}

reset(arg) {
        if(arg) return;
        add_exit("north","/wizards/rag/ruins/ruins_w");
        add_exit("east","/wizards/rag/ruins/ruins_s");

        short_desc = "At a well";
        long_desc =     "A raging storm makes it hard to see anyting. The church looks a bit\n"+
                        "better on this side but it is still slightly burned. The ground is\n"+
                        "muddy from the rain. The wall surrounding the church continues to\n"+
                        "north and east.\n";

        items = allocate(6);
        items[0] = "church";
        items[1] = "The church is burned, but a bit better on this side";
        items[2] = "wall";
        items[3] = "The wall is very old but it's still very sturdy. It is covered with vines";
        items[4] = "vines";
        items[5] = "The vines grow against the wall. They aren't strong enough to be climbed";

        set_sound(16+random(6),"Rain pours heavily down from the sky.\n");
        set_sound(22+random(6),"Thunder and lightning rage over the church.\n");

        move_object(clone_object("/wizards/rag/ruins/obj/well"),this_object());
}

fill(str) {
        object ob;
        ob = present("bucket",this_player());
        if(str == "bucket" && ob) {
                write("You fill the bucket with water.\n");
                say(this_player()->query_name()+" fills the bucket with water.\n");
                destruct(ob);
                move_object(clone_object("/wizards/rag/ruins/obj/bucket_f"),this_player());
                return 1;
        }
        if(str == "bucket" && !ob) {
                write("But you don't have a bucket.\n");
                return 1;
        }
        write("Fill what?\n");
        return 1;
}

use(str) {
	object ob;
	if(str != "winch") return;
	ob = present("bucket",this_player());
	if(!ob) {
		write("You lower the winch down to the well but then you\n");
		write("realize that you don't have anything to hold the water.\n");
		return 1;
	}
	if(present("bucket_f",this_player())) {
		write("But you already have a bucket full of water.\n");
		return 1;
	}
	write("You lower the winch down to the well and fill the bucket with water.\n");
	destruct(ob);
	move_object(clone_object("/wizards/rag/ruins/obj/bucket_f"),this_player());
	return 1;
}
