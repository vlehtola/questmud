inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money;
    object armour,weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(28);
    set_name("Alamrot");
    set_alias("alamrot");
    set_short("Alamrot, a noisy gnome");
    set_long("Alamrot seems quite friendly, but all the same very irritating.\n");
    set_al(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Alamrot gigglesnorts at you, and tugs on his chain.\n";
        chat_str[1] =
          "Alamrot whispers: Darvox tried to make me more intelligent by giving me this hat.\n";
        chat_str[2] =
          "Alamrot continues: It must be the only time he has failed, and giggles wildly.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Alamrot shouts: You can't do this! It's not fair!.\n";
    }
    load_chat(20, chat_str);
    load_a_chat(30, a_chat_str);

    armour = clone_object("/wizards/nalle/area/gnomehat");
    move_object(armour, this_object());
    init_command("wear hat");

    weapon = clone_object("/wizards/nalle/area/hoopak");
    move_object(weapon, this_object());
    init_command("wield staff"); 
    
    money = clone_object("obj/money");
    call_other(money, "set_money", random(22));
    move_object(money, this_object());
}

