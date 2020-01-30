inherit "obj/monster";
int i = random(2);

reset(arg) {
    object armour,armour2,weapon;
    ::reset(arg);
    if(arg) { return; }
    set_level(70 + i*3);
    set_name("lord");
    set_alias("phantomlord");
    set_short("The Phantom Lord");
    set_long("The phantom lord, a skeletal figure eminating a dark, diabolic glow.\n"+
"Its bones are darkened and filthy, partially reinforced with\n"+
"metallic blades, protruding from its limbs and torso.\n");

    set_al(-10);
    set_aggressive(1);
    set_undead(1);
    set_max_hp(50000);
    set_hp(50000);
    set_str(700);
    set_log();
    set_mage(1);
    set_block_dir("up");

    armour = clone_object("/wizards/nalle/area/eq/pharmour");
    move_object(armour, this_object());
    init_command("wear plate");

    if(i==0) { armour2 = clone_object("/wizards/nalle/area/eq/phcrown");
    move_object(armour2, this_object());
    init_command("wear crown");
}
    if(i==1) { weapon = clone_object("/wizards/nalle/area/eq/phaxe");
    move_object(weapon, this_object());
    init_command("wield axe");
}
}

