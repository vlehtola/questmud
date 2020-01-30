inherit "obj/monster";
reset(arg) {
        object money;
        object cloak,amulet,bracers;
        ::reset(arg);
        if(arg) {return; }
        set_name("gorim");
        set_race("human");
        set_alias("lord");
        set_level(50+random(25));
        set_max_hp(query_max_hp()*2);
        set_str(query_str()*1);
        set_dex(query_dex()*4);
        set_con(query_con()*3);
        set_al(40);
        set_gender(1);
        set_short("Happy looking lord called Gorim");
        set_long("Very kind and happy looking man who seems to have very\n"
                 "colourful outfit. He looks like he would not harm even\n"+
                 "a fly, but somehow you sense that this man is very very\n"+
                 "sad about something.\n");
        
        set_skill("kick", 100);
        set_skill_chance("kick", 100);
        
        set_log();
        
        amulet = clone_object("/wizards/jenny/linnake/rojut/krah_amu.c");
        move_object(amulet, this_object());
        init_command("wear amulet");

        cloak = clone_object("/wizards/jenny/linnake/rojut/gray_cloak.c");
        move_object(cloak, this_object());
        init_command("wear cloak");

        bracers = clone_object("/wizards/jenny/linnake/rojut/crystal_bracers.c");
        move_object(bracers, this_object());
        init_command("wear bracers");

}
