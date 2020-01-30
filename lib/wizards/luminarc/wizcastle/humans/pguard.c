inherit "obj/monster";
reset(arg) {
    object armour;
    ::reset(arg);
    if(arg) { return; }
    set_level(25);
    set_max_hp(query_hp()+1000);
    set_str(query_str()+100);
    set_name("guard");
    set_alias("guard");
    set_short("Farnax's personal guard");
    set_long("This is the personal guard of the Farnax. His only duty seems\n"+ 
             "to be to turn away everyone who attend to enter Farnax's\n"+
             "workroom. Shiny armours which are made of steel cover every\n"+ 
             "part of guard's muscular body. The small, green eyes are\n"+
             "glimmering behing to visor in his helmet. The guard looks\n"+
             "very skillful.\n");

    set_al(10);
    set_aggressive(0);
    set_gender(1);
    armour = clone_object("/wizards/luminarc/wizcastle/armours/gsword.c");
    move_object(armour, this_object());
    init_command("wield mace");
    armour = clone_object("/wizards/luminarc/wizcastle/armours/armour1.c");
    move_object(armour, this_object());
    init_command("wear leggings");
    set_race("human");
    set_block_dir("north");
    set_block_message("Guard stands infront of you and says: 'No way! i cannot let you in.'");
}

