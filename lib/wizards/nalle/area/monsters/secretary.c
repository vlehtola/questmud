inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(6);
    set_gender(2);
    set_race("human");
    set_name("Mrs. Kraff");
    set_alias("secretary");
    set_short("Mrs. Kraff, the mayor's secretary");
    set_long("This is Mrs Kraff. She is a woman in her fourties\n" +
             "and seems to handle lots of paperwork.\n");
    set_al(5);
    set_aggressive(0);
    set_move_at_random(0);
        set_block_dir("up");
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Mrs. Kraff states: 'I am terribly sorry but you can't see the mayor now.'\n";
        chat_str[1] =
          "The secretary examines some papers intently.\n";
        chat_str[2] =
          "Mrs Kraff mutters: 'If you really want to see him sign here, he might receive you in a month or two.'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Mrs. Kraff screams: 'You impertinent youngsters!' \n"
;
    }
    load_chat(20, chat_str);
    load_a_chat(30, a_chat_str);

}
