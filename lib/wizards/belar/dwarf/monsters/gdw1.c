inherit "obj/monster";
reset(arg) {
    object armour;
    object weapon;
    ::reset(arg);
    if(arg) { return; }
    set_name("dwarf");
    set_level(14);
    set_exp(142900);
    set_hp(1100);
    set_max_hp(1100);    
    set_str(150);
    set_dex(80);
    set_con(200);   
    set_gender(1);
    set_alias("gatekeeper");
    set_short("A dwarf gatekeeper");
    set_long("The dwarf is quite tall for a dwarf. He has a few scars in his face\n"+
             "they are a painful memory of a fight with an intruder. He has\n"+
             "been here years and therefore he is bored.\n");
    set_al_aggr(0);
    set_block_dir("west");
    set_block_message("Dwarf Grunts: I can't let you go in. The old man doesn't\n"+
                      "want to see you, come back later.\n");
    set_race("dwarf");
    armour = clone_object("wizards/belar/dwarf/eq/mail.c");
    move_object(armour, this_object());
    init_command("wear mail");
    weapon = clone_object("/wizards/belar/dwarf/eq/swo1g.c");
    move_object(weapon, this_object());
    init_command("wield sword");
}
