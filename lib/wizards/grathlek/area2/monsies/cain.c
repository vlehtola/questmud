inherit "obj/monster";
 
reset(arg) {
    string chat_str, a_chat_str;
    object money;
    object armour, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(60);
    set_name("Cain");
    set_alias("cain");
    set_short("Cain the elder.");
    set_long("Cain looks really old and wise.\n");
    set_al(10);
    set_spell_chance(80, "exs zzt strm");
    set_aggressive(0);
    set_race("dark elf");
    set_skill("cast essence", 70);
    set_skill("cast electricity", 70);
    set_skill("cast storm", 70);
    set_skill("mana control", 70);
    set_skill("chanting", 70);
    set_skill("quick chant", 80);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Cain says: Be careful my frend.\n";
        chat_str[1] =
          "Cain says: In the cathedral there are horrible things. \n";
        chat_str[2] =
          "Cain says: I have heart from a floor of ice.\n"+
          "Maybe you should try some kind of fire spell at\n"+
          "the floor.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Cain asks: Why did you attack me?\n";
    }
    load_chat(20, chat_str);
    load_a_chat(15, a_chat_str);
 
    money = clone_object("obj/money");
    call_other(money, "set_money", random(1000));
    move_object(money, this_object());

    weapon = clone_object("/wizards/grathlek/area2/eq/cstaff.c");
    move_object(weapon, this_object());
    init_command("wield club");

    armour = clone_object("/wizards/grathlek/area2/eq/brobes.c");
    move_object(armour, this_object());
    init_command("wear robes");

}
