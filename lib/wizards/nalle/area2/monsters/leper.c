inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money,weapon,armour;
    ::reset(arg);
    if (arg) { return; }
    set_level(10);
    set_name("Leper");
    set_alias("leper");
    set_short("A revolting leper");
    set_long("A filthy leper, entangled in rags is huddled on the ground, moaning.\n");
    set_al(-2);
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "The leper moans in pain and shivers.\n";
        chat_str[1] =
          "The leper whispers: Alms for a leper. Alms for a leper, please kind sir.\n";
        chat_str[2] =
          "The leper reaches for you with a mutilated hand, and crawls in your direction. \n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "The leper moans: Your body will rot before you die, sinner. \n";
    }
    load_chat(10, chat_str);
    load_a_chat(10, a_chat_str);

    armour = clone_object("/wizards/nalle/area/eq/rags");
    move_object(armour, this_object());
    init_command("wear rags");

    weapon = clone_object("/wizards/nalle/area/eq/knstaff");
    move_object(weapon, this_object());
    init_command("wield staff");

    money = clone_object("obj/money");
    call_other(money, "set_money", random(5));
    move_object(money, this_object());
}

