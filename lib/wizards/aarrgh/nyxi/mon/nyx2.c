inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object armour, armour2, armour3;
        ::reset(arg);
    if(arg) { return; }
    set_undead(1);
    call_other(this_object(), "set_level", 88);
    call_other(this_object(), "set_name", "nyx");
    set_log();
    call_other(this_object(), "set_alias", "nyx");
    call_other(this_object(), "set_short", "Nyx the mother of chaos and destruction (floating)");
    call_other(this_object(), "set_long", "A see a dark Demonic presence floating above the ground. Nyx is about two times\n"
                                          "larger than average male. The skin is grey and it is definetly undead. Nyx is glowing\n"
                                          "in the darkness and is surrounded by some evil aura. Power it holds is unbelievable.\n");
set_resists("cold", 3);
set_skill("cast ice", 150);
set_spell_chance(100, "exs brr strm");
set_skill("cast storm", 300);
set_skill("critical", 100);
set_skill("attack", 300);
set_skill("channel", 300);
set_skill("cast bolt", 150);
set_skill("chanting", 400);
set_skill("cast essence", 150);
set_skill("bare hands", 300);
set_skill("cast earth", 350);
set_skill("mana control", 350);
set_str(1010);
set_skill("deceived attack", 200);
set_skill("tumble", 300);
set_skill("find weakness", 300);
set_skill("stun", 300);
call_other(this_object(), "set_aggressive", 1);

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
