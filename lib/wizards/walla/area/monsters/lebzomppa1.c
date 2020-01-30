inherit "obj/monster"; 
 
reset(arg) {
    ::reset(arg);
    set_mage();
    set_level(18);
    set_name("zombie");
    set_short("A rotting zombie");
    set_long("This zombie rules this place.");
    set_al(0);
    set_aggressive(1);
    set_skill("cast essence", 69);
    set_skill("cast fire", 69);
    set_skill("cast ice", 69);
    set_skill("cast electric", 69);
    set_skill("cast earth", 69);
    set_skill("cast bolt", 69);
    set_skill("cast arrow", 69);
    set_skill("cast grasp", 69);
    set_skill("mana control", 21);
    set_skill("chanting", 69);
    set_dead_ob(this_object());
    set_dead_ob(this_object());
    
}
