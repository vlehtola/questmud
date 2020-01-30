inherit "obj/monster";
reset(arg) {
        object money;
        object bracers;
        ::reset(arg);
        if(arg) {return; }
        set_name("neramaia");
        set_undead(1);
        set_alias("vampire");
        set_level(68+random(12));
        set_max_hp(query_hp() + 30000);
        set_al(-50);
        set_gender(2);
        set_short("Neramaia, the mean looking vampire");
        set_long("Neramaia is an ancient vampire who used to\n"
                 "serve Odel in a dark war a few thousand years\n"+
                 "ago. Now that Odel is destroyed she is serving\n"+
                 "Mondasa and helping him to gain more power and\n"+
                 "respect. She is only wearing a magically radiating\n"+
                 "leather bracers, otherwise she is completely naked.\n");
        
        set_skill("counter spell", 100);
        set_skill("reflect spell", 100);
        set_skill("tremendous blow", 100);
        set_skill_chance("tremendous blow", 100);
        set_skill("foresee attack", 100);
        set_block_dir("south");
        set_log();
        
        bracers = clone_object("/wizards/jenny/gnael/rojut/leather_bracers.c");
        move_object(bracers, this_object());
        init_command("wear bracers");

}
