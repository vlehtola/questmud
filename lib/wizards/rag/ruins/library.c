inherit "room/room";

reset(arg) {
        if(!present("librarian")) {
                move_object(clone_object("/wizards/rag/ruins/mon/librarian"),this_object());
        }
        if(arg) return;
        add_exit("west","/wizards/rag/ruins/tower");

        short_desc = "In the church library";
        long_desc =     "The library is a small chamber next to the church tower. Most libraries\n"+
                        "are not placed on top of a church, but you come to the conclusion that\n"+
                        "the priests didn't want the common people to come here. There are a few\n"+
                        "shelves next to the eastern wall. There is a small desk in front of the\n"+
                        "shelves. A thick layer of dust has descended everywhere. Some wine bottles\n"+
                        "can be spotted in one of the corners. There aren't any windows here, which\n"+
                        "gives this chamber a gloomy look.\n";

        items = allocate(6);
        items[0] = "shelves";
        items[1] = "The shelves are full of old books. Most books are written about divine powers";
        items[2] = "desk";
        items[3] = "The desk seems to be just like a normal desk";
        items[4] = "bottles";
        items[5] = "The bottles are empty";

        set_not_out(1);
        set_sound(29+random(6),"You hear the pouring rain and the raging thunder.\n");
}
