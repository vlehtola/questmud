inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(14);
    set_race("human");
    set_gender(1);
    set_name("Esquire");
    set_alias("esquire");
    set_short("An esquire, sweeping the floor in here");
    set_long("A middle-aged esquire, sweeping the floor. He seems to\n" +
             "wear a deep frown on his face.\n");
    set_al(5);
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Esquire mutters: 'I used to be a Knight before Nalle tuned me.'\n";
        chat_str[1] =
          "Esquire growls: 'You lucky, lucky bastard.'\n";
        chat_str[2] =
          "The esquire sweeps the floor with unimaginable enthusiasm. \n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Esquire grunts: 'Oh, piss off.' \n";
    }
    load_chat(10, chat_str);
    load_a_chat(10, a_chat_str);

   weapon = clone_object("/wizards/nalle/area/eq/broom");
    move_object(weapon, this_object());
    init_command("wield broom"); 
   
}
