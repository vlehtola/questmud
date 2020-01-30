inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    ::reset(arg);
    if (arg) { return; }
    set_animal();
    set_gender(0);
    set_level(17);
    set_name("owl");
    set_alias("owl");
    set_short("An owl, sitting in a tree");
    set_long("This small owl looks at you amusedly from a tree.\n" +
             "It has big round eyes and a brown coat of feathers.\n");
    set_al(1);
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(1);
        chat_str[0] = "The owl hoots at the moon longingly.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "The owl's head rotates wildly as it tries to keep track of your attacks.\n";
    }
    load_chat(10, chat_str);
    load_a_chat(20, a_chat_str);

}

