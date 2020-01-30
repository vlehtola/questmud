inherit "room/room";
 
reset(arg) {
        if(arg) return;
        add_exit("west","room2");
        add_exit("south","room5");
        add_exit("east","room6");
        add_exit("out","entrance");
        short_desc = "Inside the cathedral";
        long_desc = "You are standing on a cold stone floor inside the cathedral. The only light comes\n" +
                    "from the stained glass windows high up, leaving most of blackened stonework shadowed. \n" +
                    "The stench of rotten tissue and decaying corpses fill the air, making you almost gag. \n" +
                    "Some dust-laden dangling cobwebs fill the corners of the room, and a cluster of tall iron\n" +
                    "candlesticks tries amplify the light, only emphasizing the shadows.\n";
        items = allocate(2);
        items[0] = "candlesticks";
        items[1] = "Tall iron candlesticks cover the walls";
        property = allocate(1);
        property[0] = "no_summon";
}







