inherit "obj/monster";

object money, weapon, gloves, robe;

reset(arg) {
    string chat_str, a_chat_str;
    ::reset(arg);
    set_level(35);
    set_name("tutor");
    set_alias("mage");
    set_short("The tutor dressed in a green robes");
    set_long("This man looks very old and he has a grey beard.\n");
    set_al(50);
    set_aggressive(0);
    set_gender(1);
    
    set_skills("cast essence", 90);
    set_skills("cast bolt", 70);
    set_skills("cast poison", 60);
    set_skills("mana control", 90);
    set_skills("chanting", 80);
    set_skills("mastery of poison", 80);
    
    set_spell_chance(100, "exs poi blt");
    experience += experience / 2;
    if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] =
          "Tutor says: 'If you want to be a true mage, you have to pass the Test.'\n";
        chat_str[1] =
	  "Tutor says: 'To pass the Magetest you should be able to inflict some other\n"+
 	  "damage than physical, which means the Earth Element.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Tutor says: 'So, you are evil after all..'\n";
    }
    load_chat(50, chat_str);
    load_a_chat(20, a_chat_str);
        
    money = clone_object("obj/money");
    call_other(money, "set_money", random(1000));
    move_object(money, this_object());

    weapon = clone_object("wizards/onarion/tower/eq/dagger.c");
    move_object(weapon, this_object());
    init_command("wield dagger");
    
    gloves = clone_object("wizards/onarion/tower/eq/tring.c");
    move_object(gloves, this_object());
    init_command("wear ring");

    robe = clone_object("wizards/onarion/tower/eq/green_robe.c");
    move_object(robe, this_object());
    init_command("wear robes");


    call_out("leave", 170);
}                                

leave() {
    if(!this_object()->query_attack()) {
        say("The tutor leaves.\n");
        destruct(this_object());
	destruct(money);
	destruct(weapon);
	destruct(gloves);
    } else {
        call_out("leave", 20);
    }
}
