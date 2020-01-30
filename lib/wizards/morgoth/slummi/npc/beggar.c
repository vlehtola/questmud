inherit "obj/monster";
 
reset(arg) {
    string chat_str, a_chat_str;
    object armour;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 2);
    call_other(this_object(), "set_name", "beggar");
    call_other(this_object(), "set_alias", "man");
    call_other(this_object(), "set_short", "A filthy beggar");
    call_other(this_object(), "set_long",
    "This old man is here begging for some coins.\n");
    call_other(this_object(), "set_al", -10);
    call_other(this_object(), "set_race", "human");
    call_other(this_object(), "set_aggressive", 0);
 
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Beggar rubs his hands.\n";
        chat_str[1] =
          "Beggar says 'Damn, it's so cold..'\n";
        chat_str[2] =
          "Beggar asks 'Can you lend me a few coins?'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Beggar screams 'Why the hell did you attack me!'\n";
    }
    load_chat(20, chat_str);
    load_a_chat(15, a_chat_str);
 
    armour = clone_object("/wizards/morgoth/slummi/item/gloves");
    move_object(armour, this_object());
    init_command("wear gloves");
}
