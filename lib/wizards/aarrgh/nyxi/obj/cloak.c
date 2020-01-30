inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_name("cloak");
    set_alias("cloak");
set_short("A dark cloak of sacrifice");
    set_long("This dark cloak is an ordinary looking cloak except it glows dim red. You can almost\n"
             "notice some blood stained on the cloak. The cloak flows with magical energy as\n"
             "it waves in the wind. This cloak is ancient.");
    set_ac(5);
    set_value(5000);
    set_weight(150);
    set_stats("int", 6);
    set_stats("wis", 5);
    set_stats("con", -3);
    set_stats("spr", 20);
    set_stats("dex", -10);
    set_slot("cloak");

}
