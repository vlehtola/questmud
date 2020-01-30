inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(12);
    set_animal();
    set_name("Pudding");
    set_alias("pudding");
    set_short("A christmas pudding with a runny nose");
    set_long("This pudding is sad because George, the leader of the\n" +
             "pudding tribe, was taken prisoner by the Chamron's knights.\n");
    set_al(2);
    set_block_dir("east");
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "The pudding sniffs sadly.\n";
        chat_str[1] =
          "The pudding looks at you and goes: 'Pop!' \n";
        chat_str[2] =
          "The pudding toddles around in circles.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "The pudding meeps furiously.\n"
;
    }
    load_chat(10, chat_str);
    load_a_chat(10, a_chat_str);

}
