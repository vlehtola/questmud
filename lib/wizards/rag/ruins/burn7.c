inherit "room/room";
object monster, monster2;

reset(arg) {
        if(!monster) {
                monster = clone_object("/wizards/rag/ruins/mon/gdemon");
                move_object(monster,this_object());
        }
        if(arg) return;
        if(!monster2) {
                monster2 = clone_object("/wizards/rag/ruins/mon/bloodwind");
                move_object(monster2,this_object());
        }
        add_exit("north","/wizards/rag/ruins/burn1");
        add_exit("south","/wizards/rag/ruins/burn8");
        
        short_desc = "A bridge over a burning lake";
        long_desc =     "Intensive heat flows from the burning lake beneath your feet. Massive\n"+
                        "bridges arch over burning lava. There are several levels of bridges\n"+
                        "and on each level you can see many soldiers training under the burning\n"+
                        "whips of guarding demons. Some soldiers fall to the lake but they are\n"+
                        "instantly replaced with new trainees. This bridge seems to be the best\n"+
                        "place to observe the ongoing fights. There is a huge flaming pillar at\n"+
                        "the end of the bridge.\n";

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
        
