inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money;
    object weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(42);
    set_name("Sigfried");
    set_alias("sigfried");
    set_short("Sigfried the Knight of the Black Rose");
    set_long("Sigfried was once turned into undead, for an act known by few.\n");
    set_al(-15);
    set_aggressive(0);
    set_spell_chance(60, "exs brr blt");
    set_skill("cast essence", 50);
    set_skill("cast ice", 50);
    set_skill("cast bolt", 50);
    set_skill("mana control", 10);
    set_skill("chanting", 10);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Sigfried whispers: I can still feel the pain.\n";
        chat_str[1] =
          "Sigfried whispers: If I were freed, I could destroy this pathethic fortress.\n";
        chat_str[2] =
          "Sigfried curses the magical chains linking him to the wall. \n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "A red fire burns deep in Sigfried's eyes. \n";
    }
    load_chat(10, chat_str);
    load_a_chat(10, a_chat_str);

   weapon = clone_object("/wizards/nalle/area/sigsword");
    move_object(weapon, this_object());
    init_command("wield sword");

    money = clone_object("obj/money");
    call_other(money, "set_money", random(5));
    move_object(money, this_object());
}

