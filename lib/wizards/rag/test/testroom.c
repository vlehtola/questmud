inherit "room/room";
object m1, m2;

reset(arg) {
        if(!m1) {
                m1 = clone_object("/wizards/rag/test/race_first");
                move_object(m1,this_object());
        }
        if(!m2) {
                m2 = clone_object("/wizards/rag/test/level_first");
                move_object(m2,this_object());
        } 

        if(arg) return;

        add_exit("leave","/wizards/rag/workroom");
        add_exit("east","/wizards/rag/test/test2");

        short_desc = "Rag's testroom";
        long_desc = "This is Rag's room for testing various things.\n"+
                        "Various machines are scattered around the room and\n"+
                        "smoke rises from most of them.\n";
        set_light(1);
        set_not_out(1);

}
