inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(30);
    set_name("Elraak");
    set_alias("elraak");
    set_short("Elraak, the mage that failed");
    set_long("Elraak looks like a peculiar little man.\n");
    set_al(0);
    set_spell_chance(60, "exs fla grs");
    call_other(this_object(), "set_aggressive", 0);
    set_skill("cast essence", 90);
    set_skill("cast fire", 90);
    set_skill("cast grasp", 10);
    set_skill("mana control", 70);
    set_skill("chanting", 70);
    set_move_at_random(0);
        set_block_dir("portal");
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Elraak mentally contacts you, but you can't make out a word he says.\n";
        chat_str[1] =
          "Elraak screams as he pokes himself in the eye: Where are my hands?\n";
        chat_str[2] =
          "Elraak directs a wonderful lightningbolt at a runaway familiar. \n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Elraak attempts to zap you, but as usual, fails.\n"
;
    }
    load_chat(20, chat_str);
    load_a_chat(30, a_chat_str);

    money = clone_object("obj/money");
    call_other(money, "set_money", random(22));
    move_object(money, this_object());
}
