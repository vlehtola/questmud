inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(6);
    set_name("The massive dog");
    set_alias("dog");
    set_short("A massive guard dog.");
    set_long("This is Mr Billeth's guard dog. It's mouth seems the size of a bucket and saliva is flows out of it .\n");
    set_al(1);
    set_aggressive(1);
    set_move_at_random(0);
        set_block_dir("south");
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "The dog barks relentlessly.\n";
        chat_str[1] =
          "The dog howls.\n";
        chat_str[2] =
          "Someone from inside the house starts laughing madly as the dog charges for you. \n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Someone shouts from inside the house: Show him what we do to intruders at Mr Billeth's. \n"
;
    }
    load_chat(10, chat_str);
    load_a_chat(10, a_chat_str);

    money = clone_object("obj/money");
    call_other(money, "set_money", random(5));
    move_object(money, this_object());
}
