inherit "obj/monster";
 
reset(arg) {
    string chat_str, a_chat_str;
    object money;
    object weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(33);
    set_name("Belzar");
    set_alias("belzar");
    set_short("Arch bishop Belzar.");
    set_long("He seems to gone mad for searving his dark lords.\n");
    set_al(-20);
    set_spell_chance(80, "exs ssh bls");
    set_aggressive(0);
    set_block_dir("east");
    set_skill("cast essence", 70);
    set_skill("cast acid", 70);
    set_skill("cast blast", 70);
    set_skill("mana control", 70);
    set_skill("chanting", 70);
    set_skill("quick chant", 80);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Belzar says: You are never gonna get past me.\n";
        chat_str[1] =
          "Belzar Lafs at you. \n";
        chat_str[2] =
          "Belzar screams: AAARRRRRRRRRRGGGGHHH !\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Belzar screams: Hahaha do you all wanna die?\n";
    }
    load_chat(20, chat_str);
    load_a_chat(15, a_chat_str);
 
    money = clone_object("obj/money");
    call_other(money, "set_money", random(1000));
    move_object(money, this_object());

    weapon = clone_object("/wizards/grathlek/area2/eq/bstaff.c");
    move_object(weapon, this_object());
    init_command("wield claymore");
}
