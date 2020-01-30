inherit "obj/monster";
string chat_str, a_chat_str;

reset(arg) {

    ::reset(arg);

    if (arg) { return; }

    set_level(40);
    set_name("mummy");
    set_alias("mummy");
    set_undead(1);
    set_short("A lunatic mummy clumping forward");
    set_long("You are looking at a very thin and weak mummy.\n"+
                    "The mummy is clumping forward to the endless darkness.\n"+
                    "The mummy acts like a lunatic and talks to itself.\n"+
                    "You can see some gauzes dropping from the mummy.\n");
    set_al(-100);
    set_aggressive(0);

        if (!chat_str) {
        chat_str = allocate(1);
        chat_str[0] = "Mummy roars loudly.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Mummy says: 'Now I have to kill you!'\n";
    }
    load_chat(3, chat_str);
    load_a_chat(3, a_chat_str);

}
