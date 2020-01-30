inherit "obj/monster";

reset(arg) {

    object armour;
    object weapon;
    ::reset(arg);
    if(arg) { return; }
    
    set_level(40);
    set_name("giant");
    set_alias("guard");
    set_race("giant");
    set_short("A strong giant guarding the house");
    set_long("A massive and extremely strong giant stands here guarding\n"+
             "the house. He eyes you suspiciously and is ready to defend\n"+
             "himself if needed.\n");
    set_al(0);
    set_aggressive(0);
    set_al_aggr(200);
    set_gender(1);
    set_block_dir("enter");
    set_block_message("The giant booms 'HALT! No one is allowed to enter! Heinr has a\n"+
                      "visitor!'");
    
    weapon = clone_object("/wizards/siki/island/eq/club");
    move_object(weapon,this_object());
    init_command("wield club");
    armour = clone_object("/wizards/siki/island/eq/larmour");
    move_object(armour,this_object());
    init_command("wear armour");


}

