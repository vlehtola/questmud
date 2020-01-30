inherit "obj/weapon";

start() {
    set_class(8);
    set_sub_type("great axe");
    set_alias("stinger");
    set_short("The Stinger, an ancient axe covered with blood");
    set_long("An ancient, tyrannous, black-edged axe is made of some black metal.\n"+
             "Its edge is dull, because it's unground. It's covered with numerous\n"+
             "stains of blood.\n");
    set_stats("str", 4);
    set_stats("damage",3);
}
