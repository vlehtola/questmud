inherit "obj/monster";
reset(arg) {
        object money;
        object necklace;
        ::reset(arg);
        if(arg) {return; }
        set_name("gflaefg");
        set_race("ogre");
        set_mage(1);
        set_alias("minion");
        set_level(55+random(10));
        set_max_hp(query_max_hp()*2);
        set_al(-25);
        set_gender(1);
        set_short("A dark robed ogre-mage named Gflaefg");
        set_long("A huge ogre-mage with strong looking hands and extremely\n"
                 "sharp looking eyes. His robe is all black, but you can\n"+
                 "smell that there is also blood on the robe. He also has a\n"+
                 "gorgeous looking magical necklace on his neck.\n");
        
        set_skill("counter spell", 100);
        set_skill("cast ice", 100);
        set_skill("cast fire", 100);
        set_skill("cast electric", 100);
        set_skill("cast essence", 100);
        set_skill("cast earth", 100);
        set_skill("mana control", 60);
        set_skill("cast bolt", 50);
        set_skill("reflect spell", 100);
        set_block_dir("south");
        set_log();
        
        necklace = clone_object("/wizards/jenny/gnael/rojut/diamond_necklace.c");
        move_object(necklace, this_object());
        init_command("wear necklace");

}
