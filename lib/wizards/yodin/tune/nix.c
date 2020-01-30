inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object armour, armour2, armour3;
        ::reset(arg);
    if(arg) { return; }
    set_undead(1);
    set_level(88);
    set_name("nyx");
    set_mage(1);
    set_log();
    set_alias("nyx");
    set_short("Nyx the mother of chaos and destruction (floating)");
    set_long("A see a dark Demonic presence floating above the ground. Nyx is about two\n"
             "times larger than average male. The skin is grey and it is definetly undead.\n"
             "Nyx is glowing in the darkness and is surrounded by some evil aura. Power it\n"
             "holds is unbelievable.\n");
set_resists("cold", 3 + random(10));
set_mage();
set_skill("cast ice", 150);
set_spell_chance(100, "exs brr strm");
set_skill("cast storm", 100);
set_skill("critical", 100);
set_skill("attack", 100);
set_skill("channel", 100);
set_skill("cast bolt", 100);
set_skill("chanting", 100);
set_skill("cast essence", 100);
set_skill("bare hands", 100);
set_skill("cast earth", 100);
set_skill("mana control", 100);
set_str(1010);
set_skill("deceived attack", 100);
set_skill("tumble", 100);
set_skill("find weakness", 100);
set_skill("stun", 100);
set_aggressive(1);

    if (!a_chat_str) 
    {
         a_chat_str = allocate(3);
         a_chat_str[0] = "Nyx mentally contacts you: You cannot destroy me fools!\n";
         a_chat_str[1] = "Nyx flies towards you!\n";
    }


    load_chat(40, chat_str);
    load_a_chat(20, a_chat_str);


    armour = clone_object("/wizards/aarrgh/nyxi/obj/amulet.c");
    move_object(armour, this_object());
    init_command("wear amulet");

    armour2 = clone_object("/wizards/aarrgh/nyxi/obj/robe.c");
    move_object(armour2, this_object());
    init_command("wear robe");

    armour3 = clone_object("/wizards/aarrgh/nyxi/obj/boots.c");
    move_object(armour3, this_object());
    init_command("wear boots");

 
}
