inherit "obj/monster";

reset(arg) {
    object armour;
    object weapon;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_race("human");
    set_level(random(5) + 38);
    set_name("rabbi");
    set_short("A rabbi, wearing white clothing");
    set_long("A rabbi, conducting the praying and chanting.\n");
    set_al(15);
    set_al_aggr(200);

    set_max_hp(query_hp() * 3);
    set_hp(query_max_hp());
    set_str(query_str() + 50);

    armour = clone_object("/wizards/nalle/jerusalem/eq/turban");
    move_object(armour, this_object());
    init_command("wear turban");

    weapon = clone_object("/wizards/nalle/jerusalem/eq/staff");
    move_object(weapon, this_object());
    init_command("wield staff");
}
