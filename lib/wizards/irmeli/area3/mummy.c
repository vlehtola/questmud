inherit "obj/monster";



reset(arg) {

    string chat_str, a_chat_str;

    object money; 

    ::reset(arg);

    if (arg) { return; }

    set_level(29);

    set_name("mummy");

    set_alias("mummy");

    set_short("A lunate mummy clumping forward");

    set_long("You are looking very thin and weak mummy. Mummy is clumping forward to the endless darkness. Mummy acts like lunate and talks with itself.\n");

    set_al(10);

    set_aggressive(0);

        if (!chat_str) {

        chat_str = allocate(1);

        chat_str[0] =

          "Mummy whines to you.\n";

    }

    if (!a_chat_str) {

        a_chat_str = allocate(1);

        a_chat_str[0] = "Mummy says: 'Leave me alone.'\n";

    }

    load_chat(7, chat_str);

    load_a_chat(3, a_chat_str);



    money = clone_object("obj/money");

    call_other(money, "set_money", random(7));

    move_object(money, this_object());

    

}



