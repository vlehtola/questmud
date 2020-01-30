inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object weapon;
    ::reset(arg);
    if (arg) { return; }
    set_animal();
    set_gender(0);
    set_level(20);
    set_name("dog");
    set_alias("Dog");
    set_short("A neglected dog");
    set_long("A dog of unidentifiable breed. It looks like it has been\n"+
             "neglected for a long period of time. Its fur is messy\n"+
             "and has the sad look of an abandoned pet it in its eyes.\n");
    set_al(1);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] = "The dog whimpers silently.\n";
        chat_str[1] = "The dog licks its paws.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
 a_chat_str[0] = "The dog growls viciously.\n";
    }
    load_chat(10, chat_str);
    load_a_chat(20, a_chat_str);

}

