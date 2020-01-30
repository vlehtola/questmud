inherit "obj/monster";

reset(arg) {
    object armour,armour2,armour3;
    int i;
    ::reset(arg);
    if (arg) { return; }
    set_level(42);
    set_name("assassin");
    set_alias("sorcerer");
    set_short("The Soul Assassin, Sorcerer of the Enchantress (charmed)");
    set_long("An old and wise man with elegant-look, magician from ancient times. His\n"+
             "elegancy consists of long, grey beard, curly, grey hair and soft skin.\n"+
             "He is a bit of overweighted, like any other old man in his age. Lore of\n"+
             "magic powers is familiar to him. He is one out of three minions, minions\n"+
             "of the Enchantress. He is filled with enchantment of the Enchantress.\n");

    set_race("human");
    set_gender(1);
    i = random(3);
    set_log();
    set_max_hp(35000);
    set_hp(35000);
    set_al(10);
    set_aggressive(1);
    set_spell_chance(90, "chl xfr min");
    set_skill("channel", 100);
    set_skill("cast divine", 100);
    set_skill("cast transfer", 100);
    set_skill("cast minor", 100);


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
