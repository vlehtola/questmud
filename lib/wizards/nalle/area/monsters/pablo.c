inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(16);
    set_gender(1);
    set_race("human");
    set_name("Pablo");
    set_alias("pablo");
    set_short("Pablo, talking to a lady");
    set_long("Pablo seems to have seduced one of the knights' ladies,\n" +
             "who is listening from behind a bush.\n");
    set_al(-5);
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Pablo sighs into the bushes: 'Oh my darling!'\n";
        chat_str[1] =
          "A female voice whispers: 'What if Henry finds out?'\n";
        chat_str[2] =
          "Pablo moans: 'Henry cannot stand between our true love!'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Pablo screams: 'I confess it all!' \n";
    }
    load_chat(10, chat_str);
    load_a_chat(10, a_chat_str);

  weapon = clone_object("/wizards/nalle/area/eq/knsword");
    move_object(weapon, this_object());
    init_command("wield sword");

}
