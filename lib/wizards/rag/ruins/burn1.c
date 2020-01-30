inherit "room/room";
object monster;

reset(arg) {
        if(!monster) {
                monster = clone_object("/wizards/rag/ruins/mon/fire");
                move_object(monster,this_object());
        }
        if(arg) return;
        add_exit("north","/wizards/rag/ruins/junction");
        add_exit("southwest","/wizards/rag/ruins/burn2");
        add_exit("south","/wizards/rag/ruins/burn7");
        add_exit("southeast","/wizards/rag/ruins/burn6");

        short_desc = "A bridge over a burning lake";
        long_desc =     "Intensive heat flows from the burning lake beneath your feet. Massive\n"+
                        "bridges arch over burning lava. There are several levels of bridges\n"+
                        "and on each level you can see many soldiers training under the burning\n"+
                        "whips of guarding demons. Some soldiers fall to the lake but they are\n"+
                        "instantly replaced with new trainees. A wide bridge is leading south\n"+
                        "and some minor bridges lead to southwest and southeast. A flaming pillar\n"+
                        "can be seen to the south.\n";

        items = allocate(2);
        items[0] = "pillar";
        items[1] = "There seems to be something burning within the pillar";

        set_not_out(1);
}

chant(str) {
        if(str == "glacies") {
        tell_room(this_object(),"The scroll cools down the heat for just a second.\n");
        return 1;
        }
}
        
