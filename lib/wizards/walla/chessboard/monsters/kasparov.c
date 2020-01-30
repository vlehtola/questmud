inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 50);
    call_other(this_object(), "set_name", "garry");
    call_other(this_object(), "set_alias", "garry");
    call_other(this_object(), "set_short", "Deep Blue(tm), the IBM chessmaster computer");
    call_other(this_object(), "set_short", "Garry Kasparov, the master of Chess ponders his next move");
    call_other(this_object(), "set_long", "Garry Kasparov looks with his mysterious eyes at the \n"+
                                               "Deep  Blue screen, which in return hypnotizes Garry.\n" +
                                               "Garry looks very thinksome.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);
    if (!chat_str) {
        chat_str = allocate(8);
        chat_str[0] =
          "Garry Kasparov says: Mm, it seems as though you're a tough piece of machinery.\n";
        chat_str[1] =
          "Garry Kasparov states: That was a GOOD move, even I couldn't have done better.\n";
        chat_str[2] =
          "Garry Kasparov says: White queen to b5.\n";
        chat_str[3]=
          "Garry Kasparov says: Hey! that's not CheckMate!!\n";
        chat_str[4]=
         "Garry Kasparov says: Watch this, I learned this trick from my master, Vladimir Uljanov.\n";
        chat_str[5]=
         "Garry Kasparov says: Kb6.\n";
        chat_str[6]=
         "Garry Kasparov says: Let's go to the pub and have a shot of Vodka when this is all over.\n";
        chat_str[7]=
         "Garry Kasparov says: Checkmate kamaradskaya.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Garry Kasparov: Hey, my suit! \n";
    }
    load_chat(30, chat_str);
    load_a_chat(15, a_chat_str);



    money = clone_object("obj/money");
    call_other(money, "set_money", random(10)+10);
    move_object(money, this_object());

    armour = clone_object("/wizards/walla/chessboard/weapons/staff");
    move_object(armour, this_object());
    init_command("wield staff");

    weapon = clone_object("/wizards/walla/chessboard/armour/suit");
    move_object(weapon, this_object());
    init_command("wear suit");
}

