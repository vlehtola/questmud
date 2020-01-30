inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object weapon;
    ::reset(arg);
    if (arg) { return; }
    set_gender(1);
    set_race("human");
    set_level(21);
    set_name("Henry");
    set_alias("henry");
    set_short("Henry, a knight who is seeking revenge");
    set_long("The knight is standing next to the entrance to northern hallway.\n" +
             "Henry seems to be very upset about something, which can be seen\n" +
             "from his face and eyes. Henry wields a big axe in his hands and\n" +
             "seems to whisper curses to himself.\n");
    set_al(-5);
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Henry growls: 'Retribution is the only way.'\n";
        chat_str[1] =
          "Henry booms: 'I'm gonna smash that bloody Pablo's head across the wall.'\n";
        chat_str[2] =
          "Henry tightens his grip on his axe.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Henry growls: 'It's not a wimp like you who will stop me.'\n";
    }
    load_chat(10, chat_str);
    load_a_chat(10, a_chat_str);

    weapon = clone_object("/wizards/nalle/area/eq/knaxe");
    move_object(weapon, this_object());
    init_command("wield axe");
}

