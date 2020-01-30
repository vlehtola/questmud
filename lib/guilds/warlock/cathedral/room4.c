inherit "room/room";

reset(arg) {
        if(arg) return;
        add_exit("north","room3");
        add_exit("south","/guilds/warlock/warlock5");
        short_desc = "In a darkened hallway";
        long_desc = "The room has a multitude of cases of books and scrolls on the wall. More lay scattered on a massive " +
                    "table, its surface scarred with metal cylinders, glassware of all descriptions, and clay jars sealed " +
                    "with stoppers of cork and wax, pieces of bone, half a dozen skulls of various spieces, horns and claws " +
                    "and teeth. A sarcophagus rests on one wall. Carved into the lid is a grotesque picture of a man with a " +
                    "dog's head. The lips are pulled away from a wrinkled muzzle in a horrible snarl.\n";
        items = allocate(2);
        items[0] = "item";
        items[1] = "item desc";
        property = allocate(1);
property[0] = "no_summon";
}

query_startroom() { return 1; }