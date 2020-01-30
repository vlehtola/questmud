inherit "obj/monster";

reset(arg) {
        object money,weapon,armour,boots;
        ::reset(arg);
        if(arg) { return; }
        call_other(this_object(), "set_level", random(10)+40);
        call_other(this_object(), "set_name", "demon");
        call_other(this_object(), "set_short", "A fire demon");
        call_other(this_object(), "set_long", "This demon is sergeant in demonic army." +
                                                          "Thus dangerous enemy.\n");
        call_other(this_object(), "set_al", -25);
        call_other(this_object(), "set_aggressive", 0);
        set_resists(60,0);
        set_resists(101,1);
        set_resists(15,2);
        set_resists(30,3);
        set_resists(30,4);
        set_resists(30,5);
        set_resists(30,6);
        set_resists(30,7);
        set_spell_chance(50, "exs fla arr");
        set_skill("cast essence", 80);
        set_skill("cast fire", 80);
        set_skill("cast arrow", 80);
        set_skill("mana control", 50);
        set_skill("chanting", 70);
        set_skill("quick spelling", 20);
        set_skill("stun", 60);

        weapon = clone_object("/wizards/manta/eq/dswo1.c");
        move_object(weapon, this_object());
        init_command("wield sword");

        armour = clone_object("/wizards/manta/eq/darmour1.c");
        move_object(armour, this_object());
        init_command("wear armour");

        boots = clone_object("/wizards/manta/eq/dboots1.c");
        move_object(boots, this_object());
        init_command("wear boots");

}
