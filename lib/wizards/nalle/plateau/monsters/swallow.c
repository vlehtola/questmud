inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object weapon;
    ::reset(arg);
    if (arg) { return; }
    set_animal();
    set_gender(0);
    set_level(15);
    set_name("swallow");
    set_alias("swallow");
    set_short("A swallow");
    set_long("This swallow seems to have made its nest into a coconut tree\n" +
             "Unladen, it seems to achieve passable air-speed velocities.\n");
    set_al(1);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] = "The swallow lands onto a tree branch near you.\n";
        chat_str[1] = "The swallow pecks at a coconut.\n";
        chat_str[2] = "You wonder about the swallow's flying speed.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
 a_chat_str[0] = "The swallow manages to send a coconut down at you.\n";
    }
    load_chat(10, chat_str);
    load_a_chat(20, a_chat_str);

}

