inherit "obj/monster";

reset(arg) {
        object money,weapon,armour,boots,gloves,necklace;
        ::reset(arg);
        if(arg) { return; }
        call_other(this_object(), "set_level", random(10)+50);
        call_other(this_object(), "set_name", "demon");
        call_other(this_object(), "set_short", "A large fire demon");
        call_other(this_object(), "set_long", "This demon is captain in demonic army." +
                                                          "Thus dangerous enemy.\n");
        call_other(this_object(), "set_al", -30);
        call_other(this_object(), "set_aggressive", 0);
        set_resists(80,0);
        set_resists(101,1);
        set_resists(20,2);
        set_resists(45,3);
        set_resists(45,4);
        set_resists(45,5);
        set_resists(45,6);
        set_resists(45,7);
        set_spell_chance(70, "exs fla blt");
        set_skill("cast essence", 90);
        set_skill("cast fire", 90);
        set_skill("cast bolt", 90);
        set_skill("mana control", 60);
        set_skill("chanting", 80);
        set_skill("quick spelling", 40);
        set_skill("stun", 80);
        set_skill("slash", 60);

        weapon = clone_object("/wizards/manta/eq/dswo1.c");
        move_object(weapon, this_object());
        init_command("wield sword");

        armour = clone_object("/wizards/manta/eq/darmour1.c");
        move_object(armour, this_object());
        init_command("wear armour");

        boots = clone_object("/wizards/manta/eq/dboots1.c");
        move_object(boots, this_object());
        init_command("wear boots");

        gloves = clone_object("/wizards/manta/eq/dgloves1.c");
        move_object(gloves, this_object());
        init_command("wear gloves");

        necklace = clone_object("/wizards/manta/eq/dneck1.c");
        move_object(necklace, this_object());
        init_command("wear necklace");

}
