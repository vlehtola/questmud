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
             "have ever seen.\n");
    set_race("human");
    set_al(-50);
    set_block_dir("east");
    set_aggressive(1);

    weapon = clone_object("/wizards/tiergon/eq/bcsword");
    move_object(weapon, this_object());
    init_command("wield pick");

    armour = clone_object("/wizards/tiergon/eq/bcplate");
    move_object(armour, this_object());
    init_command("wear plate");
}

