inherit "obj/monster";
 
reset(arg) {
    string chat_str;
    object money, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(24);
    set_name("Fallen one");
    set_alias("one");
    set_short("A Fallen one.");
    set_long("This is really ugly creature. It is here to kill\n"+
             "every one who try to go past this dark coner.\n");
    set_al(-30);
    set_aggressive(1);
    if (!chat_str) {
        chat_str = allocate(1);
        chat_str[0] =
          "Fallen one screams: Gonna kill you and you frends!.\n";
    }

    money = clone_object("obj/money");
    call_other(money, "set_money", random(50)+100);
    move_object(money, this_object());

    weapon = clone_object("/wizards/grathlek/area2/eq/wstaff.c");
    move_object(weapon, this_object());
    init_command("wield club");
}
