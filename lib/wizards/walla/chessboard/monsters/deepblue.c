inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 52);
    call_other(this_object(), "set_name", "machine");
    call_other(this_object(), "set_alias", "machine");
    call_other(this_object(), "set_short", "Deep Blue(tm), the IBM chessmaster computer");
    call_other(this_object(), "set_long", "Deep Blue blinks in all different colors as it \n"+
                                         "attempts to find out what his foe plans to do next.\n" +
                                          "Deep Blue notices you and starts buzzing.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);
    if (!chat_str) {
        chat_str = allocate(8);
        chat_str[0] =
          "Deep Blue buzzes: Bh4.\n";
        chat_str[1] =
          "Deep Blue buzzes: Rh-b1.\n";
        chat_str[2] =
          "Deep Blue buzzes: Hey, we're in the middle of the game, go away.\n";
        chat_str[3]=
          "Deep Blue buzzes: I think I'm gonna eat that queen of yours with my pawn.\n";
        chat_str[4]=
         "Deep Blue buzzes: Kf2.\n";
        chat_str[5]=
         "Deep Blue buzzes: Mm, I suppose that IS checkmate...\n";
        chat_str[6]=
         "Deep Blue buzzes: That was not a smart move to make, now was it ?\n";
        chat_str[7]=
         "Deep Blue buzzes: I'll castle the king with the rook to e1.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Deep Blue buzzes: Hey, stop that, you're messing my circuits ! \n";
    }
    load_chat(30, chat_str);
    load_a_chat(15, a_chat_str);



    money = clone_object("obj/money");
    call_other(money, "set_money", random(10)+10);
    move_object(money, this_object());

    armour = clone_object("/wizards/walla/chessboard/weapons/keyboard");
    move_object(armour, this_object());
    init_command("wield keyboard");

    weapon = clone_object("/wizards/walla/chessboard/armour/cables");
    move_object(weapon, this_object());
    init_command("wear cables");
}

