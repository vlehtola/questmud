inherit "room/room";

reset(arg) {
        if(arg) return;
        add_exit("north","/guilds/warlock/warlock");
        add_exit("south","room1");
        short_desc = "A strange place";
        long_desc = "This is the place where all warlock's does their summoning things. It is rumoured that this is the only place to safely summon demons.\n";
        items = allocate(2);
        items[0] = "item";
        items[1] = "item desc";
        property = allocate(1);
        property[0] = "no_summon";
}

query_summon_circle() { return 1; }
