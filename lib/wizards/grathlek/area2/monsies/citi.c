inherit "obj/monster";
 
reset(arg) {
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(22);
    set_name("Citizen");
    set_alias("citizen");
    set_short("A Citizen of Tristram.");
    set_long("He is looks like really scared and is wandering in the town.\n");
    set_al(10);
    set_aggressive(0);
    set_move_at_random(2);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Citizen says: There is horrible things in cathedral.\n";
        chat_str[1] =
          "Citizen says: I must get a beter weapon. \n";
        chat_str[2] =
          "Citizen says: I must go and ask cain for advice.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Citizen screams: Leave me alone!\n";
    }
    load_chat(20, chat_str);
    load_a_chat(15, a_chat_str);
 
    money = clone_object("obj/money");
    call_other(money, "set_money", random(100));
    move_object(money, this_object());

    weapon = clone_object("/wizards/grathlek/area2/eq/sword.c");
    move_object(weapon, this_object());
    init_command("wield sword");
}
