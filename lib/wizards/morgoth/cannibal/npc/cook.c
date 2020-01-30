inherit "obj/monster";
 
reset(arg) {
    string chat_str, a_chat_str;
    object money;
    object armour;
    ::reset(arg);
    if (arg) { return; }
    set_level(45);
    set_name("cook");
    set_alias("cook");
    set_short("Ugly cannibal cook is making some food");
    set_long("This cook is using human flesh in his soup, YUCH!\n");
    set_al(10);
    set_aggressive(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Cook asks: Do you like my kitchen?\n";
        chat_str[1] =
          "Cook says: YUMMY!\n";
        chat_str[2] =
          "Cook grumbles: This soup will be delicious.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Cook screams angrily: DON'T EVER ATTACK ME AGAIN!\n";
    }
    load_chat(20, chat_str);
    load_a_chat(15, a_chat_str);
 
    money = clone_object("obj/money");
    call_other(money, "set_money", random(5));
    move_object(money, this_object());
 
    armour = clone_object("/wizards/morgoth/cannibal/item/hat");
    move_object(armour, this_object());
    init_command("wear necklace");
}
