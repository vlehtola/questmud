inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money, weapon, gloves;
    ::reset(arg);
    set_level(20 + random(5));
    set_name("ieon");
    set_alias("apprentice");
    set_alt_name("mage");
    set_short("Ieon the Apprentice mage of the order of ice");
    set_long("This man looks quite young and he is dressed in a blue robe.\n");
    set_al(30);
    set_aggressive(0);
    set_gender(1);
    
    set_skills("cast essence", 60);
    set_skills("cast grasp", 60);
    set_skills("cast ice", 60);
    set_skills("mana control", 60);
    set_skills("chanting", 60);
    
    set_spell_chance(100, "exs brr grs");
    experience += experience / 3;
    if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] =
          "Ieon says: 'I still have to study for some years to become a true mage.'\n";
        chat_str[1] =
          "Ieon says: 'Have you already visited my friend Nyarl who lives next door?'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Ieon begs: 'Please, Sir, spare my life.'\n";
    }
    load_chat(30, chat_str);
    load_a_chat(20, a_chat_str);
        
    money = clone_object("obj/money");
    call_other(money, "set_money", random(1000));
    move_object(money, this_object());
    weapon = clone_object("wizards/onarion/tower/eq/dagger.c");
    move_object(weapon, this_object());
    init_command("wield dagger");
    gloves = clone_object("wizards/onarion/tower/eq/bgloves.c");
    move_object(gloves, this_object());
    init_command("wear gloves");
}                                



