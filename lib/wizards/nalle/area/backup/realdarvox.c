inherit "obj/monster";
 
reset(arg) {
    object money;
    object weapon,armour,armour2,armour3,weapon2;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 80);
    call_other(this_object(), "set_exp", 21000000);
    call_other(this_object(), "set_name", "Darvox");
    call_other(this_object(), "set_alias", "darvox");
    call_other(this_object(), "set_short", "Darvox, the master of the elements");
    call_other(this_object(), "set_long", "This is Darvox, the most dreaded magic-user.\n" +
                     "The undisputed leader of the black robed magic users is fairly\n" +
                     "young and tall. The air around him crackles from magical energy.\n");
    call_other(this_object(), "set_al", -60);
 
    set_spell_chance(99, "exs poi bls");
    call_other(this_object(), "set_aggressive", 1);
    set_skill("cast essence", 100);
    set_skill("cast poison", 100);
    set_skill("cast blast", 100);
    set_skill("mana control", 100);
    set_skill("chanting", 100);
    set_skill("dodge", 100);
    set_skill("stun", 90);
    set_skill("critical", 90);
    set_skill("pound", 90);
    set_skill("bludgeons", 90);
    set_skill("two weapons combat", 99);
    set_skill("double hit", 69);
    set_skill("axes", 90);
    set_skill("tumble", 99);
    set_skill("foresee attack", 99);  
    set_log();
 
    money = clone_object("obj/money");
    call_other(money, "set_money", random(10)+21);
    move_object(money, this_object());
 
    weapon = clone_object("/wizards/nalle/area/darvstaffnew");
    move_object(weapon, this_object());
    init_command("wield staff");
 
    armour = clone_object("/wizards/nalle/area/newdarvrobes");
    move_object(armour, this_object());
    init_command("wear robes");
 
    armour2 = clone_object("/wizards/nalle/area/newdarvboots");
    move_object(armour2, this_object());
    init_command("wear boots");
 
    armour3 = clone_object("/wizards/nalle/area/darvring");
    move_object(armour3, this_object());
    init_command("wear ring");
 
    weapon2 = clone_object("/wizards/nalle/area/redemptor");
    move_object(weapon2, this_object());
    init_command("lwield axe");

    move_object(clone_object("/wizards/nalle/area/darvstaff2");;
}
