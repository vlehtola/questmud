inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(50);
    set_name("mage");
    set_short("A mage");
    set_long("This is a healer. He will most likely heal himself in combat.\n");
    set_al(50);
    set_aggressive(0);
    set_mage();
}

