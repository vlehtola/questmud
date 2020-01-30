inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money,weapon,armour;
    ::reset(arg);
    if (arg) { return; }
    set_level(30);
    set_race("human");
    set_name("soldier");
    set_alias("soldier");
    set_short("A Duranghomian soldier");
    set_long("A soldier talking to the prisoners in a stern voice.\n");
    set_al(-1);
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "The Duranghomian mutters to himself 'Crucifixion? Yes... Good.'\n";
        chat_str[1] =
          "The Duranghomian looks at the prisoners thoughtfully.\n";
        chat_str[2] =
          "The Duranghomian scratches his chin idly.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "The Duranghomian shouts 'I'll have you crucified, you low life scum!'\n" +
        "A prisoner shouts 'What? Crucifixion? I'd do anything to be crucified, you lucky bastard!'\n";
    }
    load_chat(15, chat_str);
    load_a_chat(20, a_chat_str);

    armour = clone_object("/wizards/nalle/jerusalem/eq/rbreastplate");
    move_object(armour, this_object());
    init_command("wear breastplate");

    weapon = clone_object("/wizards/nalle/jerusalem/eq/shortsword");
    move_object(weapon, this_object());
    init_command("wield sword");

}






