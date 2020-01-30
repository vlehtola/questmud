inherit "obj/monster";

reset(arg) {
    object weapon;
    object armour;
    ::reset(arg);
    if(arg) { return; }
    set_level(20);
    set_gender(1);
    set_name("fighter");
    set_alias("envoy");
    set_short("A Black Circle envoy waiting for an audience");
    set_long("From his carriage, it is instantly obvious that this man is a high-ranking officer of the Black Circle.\n"); 
    set_al(-50);
    set_block_dir("north");
    set_aggressive(1);
    set_mage(1);
    set_race("human");
    set_spell_chance(70, "exs ssh bls");
    set_skill("cast essence", 70);
    set_skill("cast acid", 70);
    set_skill("cast blast", 70);
    set_skill("mana control", 70);
    set_skill("chanting", 70);

    weapon = clone_object("/wizards/tiergon/eq/bcsword");
    move_object(weapon, this_object());
    init_command("wield sword");

    armour = clone_object("/wizards/tiergon/eq/bcplate");
    move_object(armour, this_object());
    init_command("wear plate");
}

