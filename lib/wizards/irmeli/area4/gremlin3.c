inherit "obj/monster";



reset(arg) {

    string chat_str, a_chat_str;

    object money; 

    ::reset(arg);

    if (arg) { return; }

    set_level(12);

    set_name("gremlin");

    set_alias("warrior");

    set_short("A gremlin warrior");

    set_long("A gremlin warrior is prepairing to the war, making movements and polishing his sword. You notice that this one isen't as powerful as the earlier gremlins, but you need to be careful with it.\n");

    set_al(-12);

    set_aggressive(1);

        if (!chat_str) {

        chat_str = allocate(1);

        chat_str[0] =

          "Warrior says: 'I'm soonish ready to war.'\n";

    }

    if (!a_chat_str) {

        a_chat_str = allocate(1);

        a_chat_str[0] = "Warrior does some movements.\n";

    }

    load_chat(4, chat_str);

    load_a_chat(2, a_chat_str);



    money = clone_object("obj/money");

    call_other(money, "set_money", random(5));

    move_object(money, this_object());

    

}



