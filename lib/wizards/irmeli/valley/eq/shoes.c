inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_class(8);
    set_sub_type("boots");
    set_alias("shoes");
    set_short("A round-toed shoes made of finest moccasin");
    set_long("The tip of the shoes are round-toed, made of moccasin. The moccasin\n"+
             "is perfect material for the shoes, because it's water-repellent and\n"+
             "long-lasting. A white shoe-string is tied in the shoes, it tights up\n"+
             "the shoes on the users feet");
    set_stats("str", 6);
    set_stats("con", 6);
    set_stats("dex", 6);
    set_resists("cold", 15);
}
