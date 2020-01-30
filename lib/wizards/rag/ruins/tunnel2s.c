inherit "room/room";
object monster;

reset(arg) {
        if(!monster) {
                monster = clone_object("/wizards/rag/ruins/mon/lich");
                move_object(monster,this_object());
        }
        if(arg) return;
	add_exit("north","/wizards/rag/ruins/tunnel2");

        short_desc = "A dark chamber";
        long_desc =     "This is a dark chamber. It has been made of the same rocks as the\n"+
			"tunnel. It seems to be some kind of a workroom. A wooden desk is\n"+
			"located in the northern wall. There are some evil-looking instruments\n"+
			"on a cabinet which is placed next to the desk. Some candles are\n"+
			"burning on the desk. You spot a few books on the desk, but you can't\n"+
			"really understand them.\n";
                                                                                                                             
        items = allocate(4);
        items[0] = "instruments";
        items[1] = "There instruments are perhaps used in torturing";
        items[2] = "books";
        items[3] = "You get a really bad feeling about these books";

        set_not_out(1);
	set_light(3);
}
