inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object armour,weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(40 + random(7));
    set_mage(1);
    set_name("alevric");
    set_race("giant");
    set_alias("drow");
    set_gender(1);
    set_short("Alevric the Drow");
    set_long("Alevric seems young and very powerful. The greyish figure is\n" +
             "standing near the stairway, blocking the entrance to the upper\n" +
             "part of the tower. Weak sparkles can be seen floating around\n" +
             "his fingertips.\n");
    set_str(query_str() + 100);
    set_dex(query_dex() + 200);
    set_int(query_int() + 500);
    set_max_hp(11800 + random(401));
    set_hp(query_max_hp());
    set_al(-5);
    set_log();
    set_move_at_random(0);
    set_aggressive(0);
    set_block_dir("up");

    set_spell_chance(88, "exs zzt blt");
    set_skill("cast essence", 99);
    set_skill("cast electric", 99);
    set_skill("theory of electricity", 100);
    set_skill("cast blast", 99);
    set_skill("mana control", 70);
    set_skill("chanting", 70);
    set_skill("tumble", 50);
    set_skill("dodge", 80);
    set_skill("alertness", 80);
    set_skill("foresee attack", 80);
    
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Alevric checks that his pouches are in right place.\n";
        chat_str[1] =
          "Alevric says: 'Darvox would kill you in a second. I've heard he can clone copies of himself.'\n";
        chat_str[2] =
          "Alevric says: 'Darvox's clones don't have any powerful equipment, though.'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Alevric shouts: 'My Shalafi will kill you when he hears of this!'\n";
    }
    load_chat(15, chat_str);
    load_a_chat(30, a_chat_str);

    armour = clone_object("/wizards/nalle/area/eq/drowcloak");
    move_object(armour, this_object());
    init_command("wear cloak");

    weapon = clone_object("/wizards/nalle/area/eq/drowstaff");
    move_object(weapon, this_object());
    init_command("wield staff");

 
}
