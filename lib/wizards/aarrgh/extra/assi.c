inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object armour, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(145);
    set_name("assassin");
    set_alias("assassin");
    set_short(" ");
    set_long("jorma\n"
             "power. He is wearing dark clothes, in which you can see\n"
             "some mystic runes dancing erraticaly.\n");
    set_al(-50);
    set_move_at_random(0);
    set_skill_chance(100 "backstab");
    set_skill("backstab", 100);
    set_skill("double backstab", 100);
    set_skill("triple backstab", 100);
    set_aggressive(0);
        if (!chat_str) {
        chat_str = allocate(4);
      chat_str[0] ="Gwaeron says: I have lived a long and prosperous life.\n";
      chat_str[1] ="Gwaeron sings about ancient lands and heroes.\n";
      chat_str[2] ="Gwaeron says: I'd love to show you a way to treasury, \n"
                   "but you are not worthy enough to go in there.\n";
      chat_str[3] ="Bard looks at some papers and mumbles something about\n"
                   "how to get into the vault.\n";
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Gwaeron states in even voice: You will regret that'\n"
                        " ya puny mortals.\n";
}
    load_chat(20, chat_str);
    load_a_chat(20, a_chat_str);

    weapon = clone_object("/wizards/aarrgh/gdagger.c");
    move_object(weapon, this_object());
    init_command("wield dagger");

    armour = clone_object("/wizards/aarrgh/gbracers.c");
    move_object(armour, this_object());
    init_command("wear bracers");

    armour = clone_object("/wizards/aarrgh/gplate.c");
    move_object(armour, this_object());
    init_command("wear armor");

    armour = clone_object("/wizards/aarrgh/ggauntlets.c");
    move_object(armour, this_object());
    init_command("wear gloves");

    armour = clone_object("/wizards/aarrgh/panflute.c");
    move_object(armour, this_object());
    init_command("wear flute");

    }
