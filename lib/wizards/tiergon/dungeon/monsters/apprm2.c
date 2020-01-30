inherit "obj/monster";

reset(arg) {
    object weapon;
    string a_chat_str;
    ::reset(arg);
    if (arg) { return; }
    set_level(23);
    set_name("apprentice");
    set_alias("mage");
    set_short("An apprentice, studying a new spell");
    set_long("Before you stands a sneering stereotype of an evil wizard's apprentice: ambitious, powerful and foolish beyond all understanding.\n");
    set_al(-75);
    set_gender(1);
    set_mage(1);
    set_race("human");
    set_spell_chance(66, "exs zzt blt");
    set_skill("cast essence", 75);
    set_skill("cast electricity", 75);
    set_skill("cast bolt", 75);
    set_skill("mana control", 40);
    set_skill("chanting", 40);
 
    weapon = clone_object("/wizards/tiergon/eq/bcdagger");
    move_object(weapon, this_object());
    init_command("wield dagger");
    
    if (!a_chat_str) {
     a_chat_str = allocate(1);
     a_chat_str[0] = "The apprentice smirks at the chance of getting to test his new spell in action.\n"; 
    }
   load_a_chat(10, a_chat_str);  
}
