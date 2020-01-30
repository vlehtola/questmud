inherit "obj/monster";

reset(arg) {
    object armour,armour2,armour3;
    int i;
    ::reset(arg);
    if (arg) { return; }
    set_level(38);
    set_log();
    set_name("assassin");
    set_alias("sorcerer");
    set_short("The Soul Assassin, Sorcerer of the Enchantress (charmed)");
    set_long("An ancient fighter called 'Headhunter'. He has got his name from the\n"+
             "ancient times, when he was famous for his crusades. He cutted off heads\n"+
             "from people and stored the skulls of his victims. He is old and infirm\n"+
             "with his humbled neck, hooked nose and stooped shoulders. His well-\n"+
             "proportioned figure consists of muscles, which are well trained and\n"+
             "big. He is one out of three minions, minions of the Enchantress.\n");

    set_race("human");
    set_gender(1);
    i = random(3);
    set_al(10);
    set_max_hp(35000);
    set_hp(35000);
    set_mage(1);
    set_aggressive(1);
    set_hp(50000);
    set_skill("tremendous blow", 80);
    set_skill_chance("tremendous blow", 30);

    if(i==0) { armour = clone_object("/wizards/irmeli/valley/eq/crown.c");
    move_object(armour, this_object());
    init_command("wear crown");
}
    if(i==1) { armour = clone_object("/wizards/irmeli/valley/eq/leggings.c");
    move_object(armour,this_object());
    init_command("wear leggings");
}     
    if(i==2) { armour = clone_object("/wizards/irmeli/valley/eq/wings.c");
    move_object(armour,this_object());
    init_command("wear wings");
}
}
