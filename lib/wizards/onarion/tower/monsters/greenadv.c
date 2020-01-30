inherit "obj/monster";

int phase;

reset(arg) {
    string chat_str, a_chat_str;
    object money, weapon, cloak;
    ::reset(arg);
    set_level(35 + random(10));
    set_name("rigel");
    set_alias("adept");
    set_alt_name("mage");
    set_short("Rigel the Acid Adept in light green robes");
    set_long("The face of this man is partly burned by some acid.\n");
    set_al(30);        
    set_aggressive(0);
    set_gender(1);
    
    set_skills("cast essence", 80);
    set_skills("cast bolt", 60);
    set_skills("cast acid", 100);
    set_skills("mastery of acid", 100);
    set_skills("cast electricity", 70);
    set_skills("mana control", 60);
    set_skills("chanting", 90);

    set_spell_chance(100, "exs ssh blt");
    set_spell_chance(100, "exs fla blt");
    experience += experience / 3;
    if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] =
          "Nyarl says: 'Damn.. burned my face some weeks ago in a failed experiment.'\n";
        chat_str[1] =
          "Nyarl says: 'If you are looking for tuition, ask the old archmage Soran.'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "'Damn you!'\n";
    }
    load_chat(30, chat_str);
    load_a_chat(20, a_chat_str);
        
    money = clone_object("obj/money");
    call_other(money, "set_money", random(1000));
    move_object(money, this_object());
    
    weapon = clone_object("wizards/onarion/tower/eq/dagger.c");
    move_object(weapon, this_object());
    init_command("wield dagger");
    
    cloak = clone_object("wizards/onarion/tower/eq/gcloak.c");
    move_object(cloak, this_object());
    init_command("wear cloak");
    
}

