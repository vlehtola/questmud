inherit "obj/monster";
reset(arg) {
        object money;
        object necklace;
        ::reset(arg);
        if(arg) {return; }
        set_name("alconte");
        set_race("human");
        set_level(70+random(15));
        set_max_hp(query_max_hp()*2);
        set_str(query_str()*2);
        set_dex(query_dex()*1);
        set_con(query_con()*1);
        set_al(20);
        set_gender(1);
        set_short("Alconte, the legendary warrior");
        set_long("This man is HUGE, he is wearing only underwear and\n"
                 "necklace and his muscles glow very brightly. He has\n"+
                 "deep black eyes and he is completely bald. There is\n"+
                 "somekind of a weight hanged around his arms and legs,\n"+
                 "it looks like this man never stops training his bulging\n"+
                 "muscles.\n");
        set_skill("strike", 100);
        set_skill_chance("strike", 100);
        set_skill("stun", 100);
        set_skill("punch", 100);
        set_skill("bare hands", 100);
        set_skill("attack", 100);
        set_skill("inner strength", 100);
        set_skill("throw weight", 80);
        set_skill("enhance criticals", 80);
        set_skill("find weakness", 80);
        set_skill("tremendous blow", 40);
        set_log();
        
        necklace = clone_object("/wizards/jenny/linnake/rojut/glory_neck.c");
        move_object(necklace, this_object());
        init_command("wear necklace");

}
