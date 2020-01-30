inherit "obj/monster";



reset(arg) {

    string chat_str, a_chat_str;

    object money; 

    ::reset(arg);

    if (arg) { return; }

    set_level(14);

    set_name("gremlin");

    set_alias("knight");

    set_short("A mean gremlin knight");

    set_long("A mean looking gremlin knight is prepairing for attack to the city. This knight looks very clever and mean and it could crush your bones just like that. Meaby you should go back in the city and defend it from these fellows.\n");

    set_al(10);

    set_aggressive(0);

        if (!chat_str) {

        chat_str = allocate(1);

        chat_str[0] =

          "Knight says: 'I'm ready to attack to the city.'\n";

    }

    if (!a_chat_str) {

        a_chat_str = allocate(1);

        a_chat_str[0] = "Knight swings his fist and screams.\n";

    }

    load_chat(4, chat_str);

    load_a_chat(2, a_chat_str);



    money = clone_object("obj/money");

    call_other(money, "set_money", random(7));

    move_object(money, this_object());

    

}



