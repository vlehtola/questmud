inherit "obj/monster";
 
reset(arg) {
        object money,weapon,torso,feet,hands,amulet,head,belt,ring1,ring2;
        ::reset(arg);
        if(arg) { return; }
        call_other(this_object(), "set_level", 90);
        call_other(this_object(), "set_name", "k'zing");
        call_other(this_object(), "set_short", "K'zing The Emperor of the Hell");
        call_other(this_object(), "set_long", "This is biggest demon you have ever seen clad in fine armour emitting\n" +
                                                          "great power. It's wielding deadly weapon and flames erupt from it.\n" + 
                                                          "The demon itself is grinning at you and you have feeling it's going to kill you.\n");
        call_other(this_object(), "set_al", -80);
        call_other(this_object(), "set_aggressive", 1);
        set_resists(101,0);
        set_resists(101,1);
        set_resists(50,2);
        set_resists(75,3);
        set_resists(75,4);
        set_resists(75,5);
        set_resists(75,6);
        set_resists(75,7);
        set_spell_chance(15, "exs fla bls");
        set_spell_chance(30, "exs fla blt");
         set_spell_chance(50, "exs fla arr");
        set_spell_chance(80, "exs fla grs");
        set_skill("cast essence", 90);
        set_skill("cast fire", 90);
        set_skill("cast grasp", 90);
        set_skill("cast arrow", 80);
        set_skill("cast bolt", 70);
        set_skill("cast blast", 60);
        set_skill("mana control", 80);
        set_skill("chanting", 90);
        set_skill("quick spelling", 50);
        set_skill("mastery of fire", 50);
        
 
        weapon = clone_object("/wizards/manta/eq/dwea2.c");
        move_object(weapon, this_object());
        init_command("wield fork");
 
        torso = clone_object("/wizards/manta/eq/dtorso2.c");
        move_object(torso, this_object());
        init_command("wear robe");
 
        feet = clone_object("/wizards/manta/eq/dboots2.c");
        move_object(feet, this_object());
        init_command("wear boots");
 
        hands = clone_object("/wizards/manta/eq/dgloves2.c");
        move_object(hands, this_object());
        init_command("wear gloves");
 
        amulet = clone_object("/wizards/manta/eq/damulet2.c");
        move_object(amulet, this_object());
        init_command("wear amulet");
 
        belt = clone_object("/wizards/manta/eq/dbelt2.c");
        move_object(belt, this_object());
        init_command("wear belt");
 
        ring1 = clone_object("/wizards/manta/eq/dring1.c");
        move_object(ring1, this_object());
        init_command("wear ring");
 
      ring2 = clone_object("/wizards/manta/eq/dring2.c");
        move_object(ring2, this_object());
         init_command("wear ring");
 
        head = clone_object("/wizards/manta/eq/dhead2.c");
        move_object(head, this_object());
        init_command("wear cap");
 
}
