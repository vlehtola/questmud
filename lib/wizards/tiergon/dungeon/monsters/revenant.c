inherit "obj/monster";

reset(arg) {
    string a_chat_str;
    object weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(40);
    set_undead(1);
    set_name("Revenant");
    set_alias("revenant");
    set_short("A revenant");
    set_long("This poor man's hatred towards the people who buried him turned him into this hideous undead creature.\n");
    set_al(-2);
    set_log();
    set_aggressive(1);
    set_undead(1);
    set_block_dir("south");
    set_mage(1);
    set_spell_chance(60, "exs brr blt");
    set_skill("cast essence", 75);
    set_skill("cast ice", 75);
    set_skill("cast bolt", 75);
    set_skill("mana control", 40);
    set_skill("chanting", 40);
    set_skill("bludgeons", 100);
    set_skill("pound", 100);
        if (!a_chat_str) {
        a_chat_str = allocate(2);
        a_chat_str[0] =
          "The Revenant whispers: I can still feel the pain.\n";
        a_chat_str[1] = 
          "The Revenant growls: You cannot prevent me from taking my revenge.\n";    
 }
    weapon = clone_object("/wizards/tiergon/eq/pick");
    move_object(weapon, this_object());
    init_command("wield pick");
}

