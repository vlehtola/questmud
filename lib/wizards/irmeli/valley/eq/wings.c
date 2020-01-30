inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_slot("cloak");
    set_name("cloak");
    set_alias("wings");
    set_short("The multi-coloured wings of Serenity <divine>");
    set_long("A huge, divine looking wings with multicoloured feathers. Soft and\n"+
             "multi-coloured feathers are covering the wings. The feathers are\n"+
             "tall and extremely fragile. The wings are slightly arching,\n"+
             "separating the wings tips from each other. The wingspan is\n"+
             "over two metres wide");
    set_value(3200);
    set_weight(400);
    set_stats("int", 8);
    set_stats("con", 4);
    set_stats("spr", 15);
}
