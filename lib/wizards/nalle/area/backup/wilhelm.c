inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(16);
    set_name("Wilhelm");
    set_alias("wilhelm");
    set_short("Wilhelm the tutor");
    set_long("This is Wilhelm. He is a teacher in the local school.\n");
    set_al(-5);
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Wilhelm swings his ruler in a half circle and grins peculiarry.\n";
        chat_str[1] =
          "Wilhelm looks at a test and shakes his head in disappointment. \n";
        chat_str[2] =
          "Wilhelm mutters: Why are these pupils so interested in the plant called humulus lupulus? \n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Wilhelm screams: Ill teach you you little rascal! \n"
;
    }
    load_chat(10, chat_str);
    load_a_chat(10, a_chat_str);

    money = clone_object("obj/money");
    call_other(money, "set_money", random(5));
    move_object(money, this_object());
}
