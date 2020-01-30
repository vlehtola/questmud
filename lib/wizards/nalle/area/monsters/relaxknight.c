inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object weapon;
    ::reset(arg);
    if (arg) { return; }
    set_gender(1);
    set_race("human");
    set_level(18);
    set_name("Knight");
    set_alias("knight");
    set_short("A knight reading a book");
    set_long("A young man, relaxing himself by reading a book.\n");
    set_al(5);
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "The knight turns some pages and sighs.\n";
        chat_str[1] =
          "Knight says: 'Being a knight can also be boring you know.'\n";
        chat_str[2] =
          "The knight dozes off. \n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "The Knight shouts: 'At last! Some action!' \n";
    }
    load_chat(10, chat_str);
    load_a_chat(10, a_chat_str);

  weapon = clone_object("/wizards/nalle/area/eq/knsword");
    move_object(weapon, this_object());
    init_command("wield sword");

}