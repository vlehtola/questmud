inherit "obj/monster";

reset(arg) {
        object weapon, armour, shield, cloak;
        ::reset(arg);
        if(arg) { return; }
        set_level(53);
        set_name("finlos");
        set_race("human");
        set_str(query_str()*2);
        set_dex(query_dex()*3/2);
        set_short("Finlos sits here reading a book");
        set_long("Finlos is an impressive man. He is taller than\n"+
                "most high elves and stronger than most orcs. He\n"+
                "has completely white hair but he doesn't seem to\n"+
                "be so old to have that white hair. His cloak is\n"+
                "shining with the same light as his hair. The cloak\n"+
                "emphasizes Finlos' size. His large sword is placed\n"+
                "on the table next to a pile of books he is reading.\n");
        set_al(50);
        set_aggressive(0);
        set_al_aggr(200);
        set_gender(1);
        set_skill("tremendous blow", 80);
        set_skill_chance("tremendous blow", 50);

        set_log();

        weapon = clone_object("/wizards/rag/elf/weapons/fin_sword");
        move_object(weapon,this_object());
        init_command("wield claymore");

        shield = clone_object("/wizards/rag/elf/weapons/elf_shield");
        move_object(shield,this_object());
        init_command("wield shield");

        armour = clone_object("/wizards/rag/elf/armours/elf_mail");
        move_object(armour,this_object());
        init_command("wear mail");

        cloak = clone_object("/wizards/rag/elf/eq/wcloak");
        move_object(cloak,this_object());
        init_command("wear cloak");
}
