inherit "obj/monster";

int phase;
string chat_str, a_chat_str;

reset(arg) {
    object money, weapon, cloak;
    ::reset(arg);
    set_level(20 + random(5));
    set_name("nyarl");
    set_alias("apprentice");
    set_alt_name("mage");
    set_short("Nyarl the Apprentice mage of the order of fire");
    set_long("This man looks quite young and he is dressed in a red robe.\n");
    set_al(30);        
    set_aggressive(0);
    set_gender(1);
    
    set_skills("cast essence", 60);
    set_skills("cast grasp", 60);
    set_skills("cast fire", 60);
    set_skills("mana control", 60);
    set_skills("chanting", 60);

    set_spell_chance(100, "exs fla grs");
    experience += experience / 3;
    if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] =
          "Nyarl says: 'I still have to study for some years to become a true mage.'\n";
        chat_str[1] =
          "Nyarl says: 'If you are looking for tuition, ask the old archmage Soran.'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Mage begs: 'Please, Sir, spare my life.'\n";
    }
    load_chat(30, chat_str);
    load_a_chat(20, a_chat_str);
        
    money = clone_object("obj/money");
    call_other(money, "set_money", random(1000));
    move_object(money, this_object());
    
    weapon = clone_object("wizards/onarion/tower/eq/dagger.c");
    move_object(weapon, this_object());
    init_command("wield dagger");
    
    cloak = clone_object("wizards/onarion/tower/eq/rcloak.c");
    move_object(cloak, this_object());
    init_command("wear cloak");
    
    call_out("do_phase", random(100));
}

do_phase() {
    if(phase == 0) {
        command("west");
        chat_str = allocate(3);
        chat_str[0] =
            "Nyarl says: 'I still have to study for some years to become a true mage.'\n";
        chat_str[1] =  
            "Nyarl picks up a book from the shelve and starts studying it.\n";
        chat_str[2] =  
            "Nyarl says: 'My tutor should be here soon.'\n";
        load_chat(30, chat_str);
        call_out("tutor_arrive", random(60));
        phase = 1;
    } else {
      command("east");
      if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] =
          "Nyarl says: 'I still have to study for some years to become a true mage.'\n";
        chat_str[1] =
          "Nyarl says: 'If you are looking for tuition, ask the old archmage Soran.'\n";
      }
      load_chat(30, chat_str);
      call_out("do_phase", random(1200));
      phase = 0;
    }
}

tutor_arrive() {
    say("An old man with a green cloak and grey beard arrives.\n");
    say("Nyarl stands up and bows to him.");
    move_object(clone_object("wizards/onarion/tower/monsters/tutor"), environment(this_object()));
    chat_str = allocate(1);
    chat_str[0] =
      "Nyarl picks up a book and starts studying.\n";
    load_chat_str(5, chat_str);
    call_out("do_phase", 180);
}
