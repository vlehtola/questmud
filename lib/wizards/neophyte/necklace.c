inherit "wizards/neophyte/armour";
start() {
        set_slot("necklace");
        set_name("necklace");
        set_short("A yellow necklace of Celuwien");
        set_long("The yellow necklace is made to Celuwing by one of the elder elf's\n"+
                 "The headbang feels quite sturdy and somehow it's seems to be\n"+
                 "perfectly mentaly balanced. They say when time comes one can\n"+
                 "yell the name of Celuwien and feel totaly safe");
        set_stats("int", 4);
        set_stats("wis", 5);
        set_stats("con", 5);
        set_stats("spr", 6);
        set_value(250);
        set_weight(650);
        set_race_only("dark elf");
}
