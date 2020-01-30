inherit "obj/monster";

reset(arg) {

    object weapon,shield;
    ::reset(arg);
    if(arg) { return; }
    
    set_level(20);
    set_name("guard");
    set_alias("orc guard");
    set_race("orc");
    set_short("An orc guard");
    set_long("A big and ugly orc guarding the tunnel. He has a muscular body\n"+
             "but his skin is extremely dirty and full of scars. His dark red\n"+
             "eyes glow in the darkness and he stares at you firmly.\n");
             

    set_al(-30);
    set_aggressive(0);
    set_al_aggr(400);
    set_gender(1);
    set_skill("parry", 100);
    set_skill("shield parry", 100);
    set_skill("weapon parry", 100);
    set_block_dir("south");

    weapon = clone_object("/wizards/siki/orc/eq/sword");
    move_object(weapon,this_object());
    init_command("wield sword");

    shield = clone_object("/wizards/siki/orc/eq/shield");
    move_object(shield,this_object());
    init_command("wield shield");
}

