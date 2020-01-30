inherit "obj/monster"; 
 
reset(arg) {
    object weapon,armour; 
    ::reset(arg);
    if (arg) return;
    set_level(45+random(20));
    set_name("raistlin");
    set_alias("wizard");
    set_short("Raistlin the Wizard, Highlord of the secret Witchcraft");
    set_long("Raistlin has long, grey beard, thick silver-coloured hair and impressive,\n"+
             "beatiful eyes, which complete his wizard-like appearance. He is dressed\n"+
             "in robes, which are made to measure for him and his proportions. He is\n"+
             "rumoured to known some secret witchcraft.\n");
    set_al(0);
    set_aggressive(1);
    set_mage(1);
    set_log();
    set_gender(1);
    set_race("human");

    weapon = clone_object("/wizards/walla/area/weapons/rstaff");
    move_object(weapon, this_object());
    init_command("wield staff");
 
    armour = clone_object("/wizards/walla/area/armour/wrrobe");
    move_object(armour, this_object());
    init_command("wear robes");
 
}
