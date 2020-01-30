inherit "obj/monster";
 
reset(arg) {
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    set_level(40+random(4));
    set_name("guard");
    set_alias("guard");
    set_short("A guard watching around for intruders");
    set_long("The guard is keeping on eye for the possible intruders, who might cause\n" +
             "troubles. He has been working on a guard's duties for over twenty years,\n" +
             "working hard without getting any decent salary. He is muscular, strong\n"+
             "and ready to fight for his life, defending the city of Jericho till his\n"
             "very end.\n");
    set_al(15);
    set_aggressive(0);
    set_race("human");
    set_gender(1);
 
    armour = clone_object("/wizards/walla/area/weapons/gsword");
    move_object(armour, this_object());
    init_command("wield sword");
 
    weapon = clone_object("/wizards/walla/area/armour/ghelmet");
    move_object(weapon, this_object());
    init_command("wear helmet");
}
