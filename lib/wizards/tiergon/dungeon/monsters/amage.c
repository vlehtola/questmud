inherit "obj/monster";

reset(arg) {
    object weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(21);
    set_name("Mage");
    set_alias("mage");
    set_short("The chief magist's apprentice");
    set_long("Before you stands a sneering stereotype of an evil wizard's apprentice: ambitious, powerful and foolish beyond all understanding.\n");
    set_al(-75);
    set_gender(1);
    set_aggressive(1);    
    set_race("human");
    set_mage(1);
    set_spell_chance(66, "exs poi blt");
    set_skill("cast essence", 75);
    set_skill("cast poison", 75);
    set_skill("cast bolt", 75);
    set_skill("mana control", 40);
    set_skill("chanting", 40);
 
    weapon = clone_object("/wizards/tiergon/eq/bcdagger");
    move_object(weapon, this_object());
    init_command("wield dagger");
}

init() {
::init();
add_action("block", "east");
}
block() {
write("A phantasmal force pushes you back into the antechamber.\n");  
return 1;
}
