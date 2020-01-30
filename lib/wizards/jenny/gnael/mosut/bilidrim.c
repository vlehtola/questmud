inherit "obj/monster";
reset(arg) {
        object money;
        object boots,axe,axe2;
        ::reset(arg);
        if(arg) {return; }
        set_name("bilidrim");
        set_race("dark elf");
        set_mage(1);
        set_alias("minion");
        set_level(75+random(10));
        set_max_hp(query_hp() + 34000);
        set_al(-75);
        set_aggressive(1);
        set_gender(1);
        set_short("Bilidrim, the vicious looking dark elf");
        set_long("Bilidrim is a former royal knight of Aza'dra's elves.\n"
                 "He fought against Odel in the war a few thousands years\n"+
                 "ago, but after the war his dark side got over him and\n"+
                 "he joined Mondasa's group and he is now one of the most\n"+
                 "respected minions of Mondasa. The only thing that reminds him\n"+
                 "of the times when he used to be good are the boots of\n"+
                 "toughness which he got when he first joined the royal knights\n"+
                 "of Aza'dra\n");
        
        set_skill("counter spell", 100);
        set_skill("reflect spell", 100);
        set_skill("find weakness", 80);
        set_skill("enhance criticals", 80);
        set_skill("cast essence", 80);
        set_skill("cast earth", 80);
        set_skill("cast fire", 80);
        set_skill("cast electric", 80);
        set_skill("cast ice", 80);
        set_skill("cast bolt", 80);
        set_skill("round blow", 60);
        set_skill_chance("round blow", 40);
        set_skill("punch", 100);
        set_block_dir("south");
        set_log();
        
        boots = clone_object("/wizards/jenny/gnael/rojut/tough_boots.c");
        move_object(boots, this_object());
        init_command("wear boots");

        axe = clone_object("/wizards/jenny/gnael/rojut/battle_axe.c");
        move_object(axe, this_object());
        init_command("wield axe");

        axe2 = clone_object("/wizards/jenny/gnael/rojut/battle_axe.c");
        move_object(axe, this_object());
        init_command("wield axe");

}
