inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money;
    object armour,weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(28);
    set_name("Alevric");
    set_alias("alevric");
    set_short("Alevric the Drow");
    set_long("Alevric seems young, and very powerful.\n");
    set_al(-5);
    set_move_at_random(0);
    set_aggressive(0);
    set_block_dir("up");
    set_spell_chance(88, "exs zzt bls");
    set_skill("cast essence", 99);
    set_skill("cast electricity", 99);
    set_skill("cast blast", 99);
    set_skill("mana control", 70);
    set_skill("chanting", 70);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Alevric checks that his pouches are in the right place.\n";
        chat_str[1] =
          "Alevric says: Darvox would kill you in a second. I've heard he can clone copies of himself.\n";
        chat_str[2] =
          "Alevric says: Darvox's clones don't have any equipment though.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Alevric shouts: My Shalafi will kill you when he hears of this!.\n";
    }
    load_chat(20, chat_str);
    load_a_chat(30, a_chat_str);

    armour = clone_object("/wizards/nalle/area/drowcloak");
    move_object(armour, this_object());
    init_command("wear cloak");

    weapon = clone_object("/wizards/nalle/area/drowstaff");
    move_object(weapon, this_object());
    init_command("wield staff");

    money = clone_object("obj/money");
    call_other(money, "set_money", random(22));
    move_object(money, this_object());
}
