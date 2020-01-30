inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money,weapon,armour;
    ::reset(arg);
    if (arg) { return; }
    set_level(33);
    set_race("human");
    set_name("man");
    set_alias("leader");
    set_short("A hooded man");
    set_long("This is the leader of the People's Front of Judea.\n");
    set_al(-1);
    set_log();
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "The man booms 'The Judean People's Front??? Fuck off!'\n";
        chat_str[1] =
          "The man states 'We are the People's Front of Judea.'\n";
        chat_str[2] =
          "The man sighs 'The last member of the Popular Front died today.'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "The man shouts 'You lucky, lucky bastard!'\n";
    }
    load_chat(10, chat_str);
    load_a_chat(10, a_chat_str);

    armour = clone_object("/wizards/nalle/jerusalem/eq/jbelt");
    move_object(armour, this_object());
    init_command("wear belt");

    weapon = clone_object("/wizards/nalle/jerusalem/eq/jdagger");
    move_object(weapon, this_object());
    init_command("wield dagger");

}






