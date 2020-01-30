inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_name("crown");
    set_short("Crown of Decay");
    set_long("A crown made out of bones and other remains from corpses. It feels humid.\n");
    set_ac(10);
    set_value(2110);
    set_weight(2);
    set_stats("con", 4);
    set_stats("hpr", 1);
    set_slot("head");
}
