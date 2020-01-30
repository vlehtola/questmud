inherit "obj/monster";

reset(arg) {
    object weapon;
    object armour;
    ::reset(arg);
    if(arg) { return; }
    set_level(16);
    set_gender(1);
    set_name("fighter");
    set_alias("warrior");
    set_short("A Black Circle warrior");
    set_long("Even though he is just a common warrior of the Circle, this"+ 
             "fighter is certainly one of the most powerful warriors you"+
             "have ever seen.\n"+
             "He busily polishes his weapon ignoring all around him.\n");
    set_race("human");
    set_al(-5);
    set_block_dir("west");
    set_al_aggr(100);

    weapon = clone_object("/wizards/tiergon/eq/bcsword");
    move_object(weapon, this_object());
    init_command("wield sword");

    armour = clone_object("/wizards/tiergon/eq/bcplate");
    move_object(armour, this_object());
    init_command("wear plate");
}

