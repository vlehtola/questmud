inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money;
    ::reset(arg);
    if (arg) { return; }
    set_level(99);
    set_name("murhaaja");
    set_alias("murhaaja");
    set_short("Murhaaja!");
    set_long("Murhaaja.\n");
    set_al(-100);
    set_aggressive(1);
}
