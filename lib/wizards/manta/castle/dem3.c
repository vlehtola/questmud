inherit "obj/monster";

reset(arg) {
        object money,weapon,armour;
        ::reset(arg);
        if(arg) { return; }
        call_other(this_object(), "set_level", random(10)+30);
        call_other(this_object(), "set_name", "demon");
        call_other(this_object(), "set_short", "A medium fire demon");
        call_other(this_object(), "set_long", "This demon looks quite nasty.\n");
        call_other(this_object(), "set_al", -20);
        call_other(this_object(), "set_aggressive", 0);
        set_resists(40,0);
        set_resists(101,1);
        set_resists(10,2);
        set_resists(20,3);
        set_resists(20,4);
        set_resists(20,5);
        set_resists(20,6);
        set_resists(20,7);
        set_spell_chance(50, "exs fla grs");
        set_skill("cast essence", 60);
        set_skill("cast fire", 60);
        set_skill("cast grasp", 60);
        set_skill("mana control", 30);
        set_skill("chanting", 50);

        weapon = clone_object("/wizards/manta/eq/dswo1.c");
        move_object(weapon, this_object());
        init_command("wield sword");

        armour = clone_object("/wizards/manta/eq/darmour1.c");
        move_object(armour, this_object());
        init_command("wear armour");

}
