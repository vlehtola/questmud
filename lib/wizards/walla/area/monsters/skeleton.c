inherit "obj/monster"; 
  object armour,weapon;
 
reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_race("human");
    set_level(49);
    set_name("skeleton");
    set_short("The skeleton of the ancient mayor of Jericho");
    set_long("Mayor Leviathan's corpse, or what's left of it lies in this big tombe.\n");
    set_al(-50);
    set_mage(1);
    set_undead(1);
    set_log();

    weapon = clone_object("/wizards/walla/area/weapons/sod");
    move_object(weapon, this_object());
    init_command("wield claymore");
 }
