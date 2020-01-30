inherit "obj/monster";



reset(arg) {

    string chat_str, a_chat_str;

    object money; 

    ::reset(arg);

    if (arg) { return; }

    set_level(10);

    set_name("gremlin");

    set_alias("gremlin");

    set_short("A hairy and ungly gremlin");

    set_long("You are looking regular and young gremlin. It's hairy all over his body, making it look like monkey. It's hands is enought muscular to knock you down. It looks like it would be enought bored to his life, you should be careful if you don't want to fight with it.\n");

    set_al(-10);

    set_aggressive(1);

        if (!chat_str) {

        chat_str = allocate(1);

        chat_str[0] =

          "Gremlin says: 'Go away or i'll crush you.'\n";

    }

    if (!a_chat_str) {

        a_chat_str = allocate(1);

        a_chat_str[0] = "Gremlin walks around.\n";

    }

    load_chat(4, chat_str);

    load_a_chat(2, a_chat_str);



    money = clone_object("obj/money");

    call_other(money, "set_money", random(3));

    move_object(money, this_object());

    

}



