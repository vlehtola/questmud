inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(2);
    set_name("Mr. Billeth");
    set_alias("billeth");
    set_short("Mr. Billeth peeks up from behind the sofa");
    set_long("This is Mr Billeth. A positively pathethic sight. He is short, thin and trembling with fear.\n");
    set_al(5);
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Mr. Billeth meeps: I really didn't mean what I shouted to the dog...\n";
        chat_str[1] =
          "Mr. Billeth sobs: Please.. I'm just a confectioner, please don't kill me.\n";
        chat_str[2] =
          "The little man tries to hide under the sofa, but doesn't fit. \n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Mr. Billeth wails: Do you give up?. \n"
;
    }
    load_chat(10, chat_str);
    load_a_chat(10, a_chat_str);

    money = clone_object("obj/money");
    call_other(money, "set_money", random(5));
    move_object(money, this_object());
}
