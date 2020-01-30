inherit "obj/monster";
reset(arg) {
    int i;
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    if(arg) { return; }
    set_level(random(3)+3);
    set_name("hen");
    set_alias("hen");
    set_short("White hen is hopping around");
    set_long("One of those normal white hens. You bet you would get a nice\n"
             "meal from this.\n");
    set_al(0);
    set_aggressive(0);
    set_move_at_random(0);
    set_wc(5);
    set_hp(300);
}
