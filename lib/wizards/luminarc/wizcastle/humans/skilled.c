inherit "obj/monster";
reset(arg) {
    object armour;    
    ::reset(arg);
    if(arg) { return; }
    set_level(40);
    set_name("guard");
    set_alias("guard");
    set_short("Skilled guard searching something");
    set_long("This guard looks extremely skilled. Dull black equipments\n"+
             "are covering his body. He is currently searching something\n"+
             "from the basement. Looks like this is not his best days.\n"
             "Distrubting him would be bad idea.\n"); 
    set_race("guard");
    set_al(10);
    set_aggressive(0);
    set_gender(1);
    armour = clone_object("/wizards/luminarc/wizcastle/armours/armour1.c");
    move_object(armour, this_object());
    init_command("wear leggings");
    set_race("human");

}

