inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_name("hat");
    set_alias("hat");
    set_short("Trebor's hat");
    set_long("This large white hat seems to fit your head comfortably. There are some stains of blood on it but it doesn't matter.\n");
    set_ac(21);
    set_value(1212);
    set_weight(2);
    set_stats("str", 2);
    set_stats("dex",3);
    set_slot("head");
}
