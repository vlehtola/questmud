inherit "room/room";

reset(arg) {
        if(arg) return;
        add_exit("northeast","outmap: 59 124");
        add_exit("north","outmap: 59 124");
        add_exit("northwest","outmap: 59 124");
        add_exit("west","outmap: 59 124");
        add_exit("enter","room1");
        short_desc = "A front of Cathedral of Chaos";
     long_desc = "You have arrived at a great cathedral, carved into the face of the mountain.\n"+
                 "The cathedral is made out of black marble, and is extremely beautiful in a\n"+
                 "frightening way. Two doors made out of black oak are closed by some sort of\n"+ 
                 "magic, and the golden handles shine with a magical aura, preventing you from\n"+
                 "touching them.\n";

        items = allocate(2);
        items[0] = "cathedral";
        items[1] = "A massive cathedral, carved into the face of the mountain";
        property = allocate(1);
        property[0] = "no_summon";
}

init() {
::init();
add_action("enter", "enter");
}

//Guild is closed by Celtron, no entrance by Rag
enter() {
write("You hear a booming voice saying 'You are not allowed here!'\n");
return 1;
if(!this_player()->query_guild_level("Warlocks") && !this_player()->query_demon()) {
write("You feel too feeble to enter this place.\n");
return 1;
}
}


