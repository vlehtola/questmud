inherit "obj/monster";
reset(arg) {
        object armour,key;
        ::reset(arg);
        if(arg) {return; }
        set_name("rewalah");
        set_race("human");
   set_alias("captain");
        set_level(85+random(10));
        set_max_hp(query_max_hp()*2);
        set_experience(18353432);
        set_str(850);
        set_con(query_con()*3);
        set_al(-50);
        set_gender(1);
        set_short("Rewalah, Captain of the jailguards");
        set_long("Fearsome looking man with huge shoulders is looking very\n"
                 "mean. He is wearing expensive looking adamantium bracers \n"+
                 "and other not so expensive looking clothes.\n");
        set_skill("kick", 100);
        set_skill_chance("kick", 100);
        set_skill("stun", 100);
        set_skill("punch", 100);
        set_skill("bare hands", 100);
        set_skill("attack", 100);
        set_skill("inner strength", 100);
        set_skill("strike", 100);
        set_skill_chance("strike", 100);
        set_skill("counter spell", 100);
        set_skill("reflect spell", 100);
        set_log();
        
        key = clone_object("/wizards/jenny/linnake/rojut/gkey.c");
        move_object(key, this_object());

        armour = clone_object("/wizards/jenny/linnake/rojut/ada_bracers.c");
        move_object(armour, this_object());
        init_command("wear bracers");

}
