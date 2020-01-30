inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money;
    object weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(19);
    set_name("Diith");
    set_alias("diith");
    set_short("Diith the fearless barbarian");
    set_long("Diith is without question extremely strong and stupid.\n");
    set_al(-5);
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Diith bangs his head against the wall, making pieces of rock fly.\n";
        chat_str[1] =
          "The barbarian smashes the floor with his club.\n";
        chat_str[2] =
          "Diith looks at you hungrily and slobbers. \n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Diith relentlessly pounds your head with his club. \n";
    }
    load_chat(10, chat_str);
    load_a_chat(10, a_chat_str);

   weapon = clone_object("/wizards/nalle/area/club");
    move_object(weapon, this_object());
    init_command("wield club");

    money = clone_object("obj/money");
    call_other(money, "set_money", random(5));
    move_object(money, this_object());
}
