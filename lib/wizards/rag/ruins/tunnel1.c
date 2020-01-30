inherit "room/room";
object monster, shelter;

reset(arg) {
        if(!monster) {
                monster = clone_object("/wizards/rag/ruins/mon/gdemon");
                move_object(monster,this_object());
        }
        if(arg) return;
        if(!shelter) {
                shelter = clone_object("/guilds/spell_obj/shelter");
                move_object(shelter,this_object());
        }
        add_exit("north","/wizards/rag/ruins/tunnel1n");
        add_exit("west","/wizards/rag/ruins/tunnel2");
        add_exit("east","/wizards/rag/ruins/junction");
        add_exit("south","/wizards/rag/ruins/tunnel1s");

        short_desc = "In a massive tunnel";
        long_desc =     "This tunnel is very massive. It is made of large symmetrical white rocks.\n"+
                        "The ground also consists of the same rocks. The tunnel seems to continue\n"+
                        "far to the west. There are some chambers in the north and the south. Some\n"+
                        "torches are burning on the walls.\n";

        set_not_out(1);
        set_light(3);
}

remove() {
        object ob;
        ob = present("shelter",this_object());
        if ( ob ) {
          ob->remove();
        }
        return 1;
}
