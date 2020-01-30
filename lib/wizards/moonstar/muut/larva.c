inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(1);
    set_name("larva");
    set_alias("worm");
    set_animal();
    set_short("A larva ");
    set_long("A vigorously.\n");
    set_al(0);
    set_aggressive(1);
    set_move_at_random(0);

}

