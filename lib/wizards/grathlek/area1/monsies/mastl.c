inherit "obj/monster";
 
reset(arg) {
    object armour,armour2,weapon;
    int i;
    i = random(2);
    ::reset(arg);
    if(arg) return;
    set_level(i*5 + 58);
    set_name("leornic");
    set_alias("mage");
    set_alt_name("master");
    set_short("Master Leornic the mage");
    set_long("Leornic looks like a skilled mage. He is here studying\n"+ 
             "new spells and skills.\n");
    set_al(40);
    set_race("human");
    set_str(550);
    set_mage(10);
    set_log();

    set_skill("tremendous blow", 80);
    set_skill_chance("tremendous blow", 50);
    set_skill("stun", 75);

    if(i==1) { armour = clone_object("/wizards/grathlek/area1/eq/bbra.c");
    move_object(armour, this_object());
    init_command("wear bracers");
}
    if(i==0) { armour = clone_object("/wizards/grathlek/area1/eq/boots.c");
    move_object(armour,this_object());
    init_command("wear boots");
}     

    weapon = clone_object("/wizards/grathlek/area1/eq/lhammer.c");
    move_object(weapon,this_object());
    init_command("wield mace");
}

