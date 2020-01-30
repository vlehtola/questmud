inherit "room/room";

reset(arg) {
        if(arg) return;
        add_exit("north","room6");
        add_exit("south","room8");
        add_exit("east","/guilds/warlock/warlock3");
        short_desc = "in a faintly lit corridor";
        long_desc = "You can see big table in front of you. The dust cover that should lay over it like a gray blanket " +
                    "has been disturbed in a number of places, and scrolls are scattered all over the table. Some dissected " +
                    "corpses of smaller and bigger animals lay on the table, their inner parts neatly stacked into glass jars " +
                    "with labels on them. Dark water seems to drip down the stone walls onto the cold stone floor, creating small " +
                    "dark pools of fading color in the shadowed room.\n";
        items = allocate(2);
        items[0] = "item";
        items[1] = "item desc";
        property = allocate(1);
property[0] = "no_summon";
}
query_startroom() { return 1; }