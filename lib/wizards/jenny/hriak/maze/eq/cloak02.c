inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("cloak");
    set_short("A dark cloak with red runes");
    set_long("The cloak is soft and comfortable. Red runes have been sewed on it.\n"+
        "They seem to be emitting a magical aura which surrounds the whole cloth.\n");
    set_weight(100);
    set_slot("cloak");
    set_stats("str",-10);
    set_stats("dex",-10);
    set_stats("con",-5);
    set_stats("int",15);
    set_stats("wis",15);
    set_stats("spr",20);
}
