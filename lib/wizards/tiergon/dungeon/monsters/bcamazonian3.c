inherit "obj/monster";

reset(arg) {
    object weapon;
    object armour;
    ::reset(arg);
    if(arg) { return; }
    set_level(22);
    set_gender(2);
    set_name("guard");
    set_alias("woman");
    set_short("A female guard of the Black Circle");
    set_long("This stunningly beautiful woman is a member of the commander's personal bodyguard.\n He's a lucky bastard.\n");
    set_al(-30);
    set_aggressive(1);
    set_race("human"); 

    weapon = clone_object("/wizards/tiergon/eq/bcsword");
    move_object(weapon, this_object());
    init_command("wield pick");

    armour = clone_object("/wizards/tiergon/eq/bcplate");
    move_object(armour, this_object());
    init_command("wear plate");
}

