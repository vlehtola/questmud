inherit "obj/monster";



reset(arg) {

    string chat_str, a_chat_str;

    object money; 

    ::reset(arg);

    if (arg) { return; }

    set_level(15);

    set_name("gremlin");

    set_alias("veteran");

    set_short("A FAT gremlin veteran");

    set_long("A FAT gremlin veteran looks over hundred years old. A long and white beard similar like Santa Claus, is covering its chin. Its legs are twisted from his weight. Veterans face is atrophyed and its another eye is covered with blinker.\n");

    set_al(12);

    set_aggressive(1);

        if (!chat_str) {

        chat_str = allocate(1);

        chat_str[0] =

          "Veteran says: 'Please help me my feets are swollen.'\n";

    }

    if (!a_chat_str) {

        a_chat_str = allocate(1);

        a_chat_str[0] = "Veteran grimaces with pain when he walks around.\n";

    }

    load_chat(4, chat_str);

    load_a_chat(2, a_chat_str);



    money = clone_object("obj/money");

    call_other(money, "set_money", random(7));

    move_object(money, this_object());

    

}



