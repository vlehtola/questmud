inherit "obj/monster";

reset(arg) {
        object cloak;
        ::reset(arg);
        if(arg) { return; }
        set_level(51);
        set_name("angdal");
        set_alias("elf");
        set_race("wood elf");
        set_str(query_str()*5/2);
        set_dex(query_dex()*5/2);
        set_short("Angdal sits here meditating");
        set_long("Angdal is wearing a black hooded cloak which hides\n"+
                "his face. Judging from his features, he seems to be\n"+
                "a wood elf. You can't really tell if there's something\n"+
                "hidden under the cloak. He is just sitting here, but\n"+
                "you get the feeling that he is aware of you presence.\n");
        set_al(0);
        set_aggressive(0);
        set_al_aggr(200);
        set_gender(1);
        set_special(20);

        set_log();

        cloak = clone_object("/wizards/rag/elf/eq/bcloak");
        move_object(cloak,this_object());
        init_command("wear cloak");
}

special_move() {
        object att;
        string gender, pron;

        att = this_object()->query_attacker();
        gender = att->query_gender_string();

        gender == "it"; 
        if (gender == "male") { pron = "him"; }
        if (gender == "female") { pron = "her"; }

        tell_object(att,"Angdal suddenly grabs you and throws you down!\n");
        move_object(att,"/wizards/rag/elf/e_c3");
        tell_room(environment(this_object()),"Angdal suddenly grabs "+att->query_name()+" and throws "+pron+" down!\n");
}
