inherit "obj/monster";
 
reset(arg) {
    object weapon,armour,armour2;
    ::reset(arg);
    if(arg) { return; }
    set_race("human");
    set_gender(1);
    set_level(42+random(5));
    call_other(this_object(), "set_name", "Master");
    call_other(this_object(), "set_alias", "master");
    call_other(this_object(), "set_short", "Master of Ceremonies");
    call_other(this_object(), "set_long", "He seems to be a religious leader here.\n");
    call_other(this_object(), "set_al", -17);
 
    set_spell_chance(66, "exs brr blt");
    call_other(this_object(), "set_aggressive", 0);
    set_skill("cast essence", 90);
    set_skill("cast ice", 90);
    set_skill("cast bolt", 80);
    set_skill("mana control", 50);
    set_skill("chanting", 50);
    set_skill("stunning blast", 50);

    set_skill("strike", 90);
    set_skill("double strike", 50);
    set_skill_chance("strike", 25);
    set_str(query_str() + 100);
    set_dex(query_dex() + 50);
    set_log();
 
    weapon = clone_object("/wizards/shadow/Wolf/weapons/ceremaxe2");
    move_object(weapon, this_object());
    init_command("wield axe");
 
    armour = clone_object("/wizards/shadow/Wolf/armour/ceremhood");
    move_object(armour, this_object());
    init_command("wear hood");
 
    armour2 = clone_object("/wizards/shadow/Wolf/armour/ring");
    move_object(armour2, this_object());
    init_command("smile");
}
