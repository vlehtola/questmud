inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(21);
    set_name("The Assassin");
    set_alias("assassin");
    set_short("An assassin is inspecting the area here.");
    set_long("He is completely clad in black, and seems like a very skilled fighter.\n");
    set_al(0);
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "The assassin throws his dagger in the air and catches it skillfully.\n";
        chat_str[1] =
          "The assassin whispers: Know people you want to get rid of? \n";
        chat_str[2] =
          "The assassin stuffs his garotte under his cloak. \n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "The assassin prepares to thrust his dagger in your gut. \n"
;
    }
    load_chat(10, chat_str);
    load_a_chat(10, a_chat_str);

    money = clone_object("obj/money");
    call_other(money, "set_money", random(5));
    move_object(money, this_object());
}
