inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money, armour;
    ::reset(arg);
    if (arg) { return; }
    set_level(48);
    set_name("crow");
    set_alias("pet");
    set_short("Crow, royal pet of the emperor");
    set_long("Crow is pet of royal family. It is bigger than regular crows. Crow is all over black and it seems to act strange. There is a few corpses lying on the floor. Crow is eating one of the corpses.\n");
    set_al(-10);
    set_aggressive(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "The crow croaks.\n";
        chat_str[1] =
          "Crow says: 'You need to crawl something to get to the emperor.'\n";
        chat_str[2] =
          "Crow says: 'Do not crawl in here. You need to find the right place.'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Crow says: 'Please do not kill me. Kill the emperor.'\n";
    }
    load_chat(20, chat_str);
    load_a_chat(15, a_chat_str);

    money = clone_object("obj/money");
    call_other(money, "set_money", random(5));
    move_object(money, this_object());
    
    armour = clone_object("/wizards/irmeli/pena/equ/crown.c");
    move_object(armour, this_object());
    init_command("wear crown");
}

