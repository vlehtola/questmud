inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money,weapon,armour;
    ::reset(arg);
    if (arg) { return; }
    set_level(44);
    set_race("human");
    set_name("prisoner");
    set_alias("Prisoner");
    set_short("A prisoner");
    set_long("Chains attach this prisoner to the wall.\n");
    set_al(0);
    set_log();
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "The prisoner roars in fury.\n";
        chat_str[1] =
          "The prisoner yanks on the chains.\n";
        chat_str[2] =
          "The prisoner tries to reach you but the chains prevent him. \n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "The prisoner shouts: You are owned!. \n";
    }
    load_chat(10, chat_str);
    load_a_chat(10, a_chat_str);

    armour = clone_object("/wizards/nalle/jerusalem/eq/mask");
    move_object(armour, this_object());
    init_command("wear mask");

    weapon = clone_object("/wizards/nalle/jerusalem/eq/knife");
    move_object(weapon, this_object());
    init_command("wield dagger");

}






