inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    ::reset(arg);
    if (arg) { return; }
    set_animal();
    set_gender(0);
    set_level(40);
    set_name("bear");
    set_alias("Bear");
    set_short("A big bear");
    set_long("Wow, this animal sure is amazing. A big strong bear,\n" +
             "you don't want to piss him off.\n");
    set_al(1);
    set_aggressive(random(3)%2);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
   chat_str[0] = "The bear yawns tiredly.\n";
   chat_str[1] = "The bear mutters something about a huntmeister.\n";
   chat_str[2] = "The bear growls mightily.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "The bear smacks you around with its paws.\n";
    }
    load_chat(10, chat_str);
    load_a_chat(20, a_chat_str);

}

