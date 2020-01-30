inherit "obj/monster";
 
reset(arg) {
    string chat_str, a_chat_str;
    object money;
    object armour,weapon;
    ::reset(arg);
    set_level(60);
    set_name("king");
    set_alias("cannibal");
    set_short("Cannibal king is sitting here");
    set_long("This cannibal is very big and ugly.\n" + 
             "He seems to be a king of the cannibals.\n");
    set_al(0);
    set_log();
    set_spell_chance(50, "exs poi blt");
    set_aggressive(0);
    set_max_hp(50000);
    set_hp(50000);
    set_skill("cast essence", 50);
    set_skill("cast poison", 50);
    set_skill("cast bolt", 50);
    set_skill("mana control", 20);
    set_skill("quick spelling", 50);
    set_skill("chanting", 40);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "King swings his Flesh eater.\n";
        chat_str[1] =
          "King mumbles: HUUGABUUGA!\n";
        chat_str[2] =
          "King asks: What are you doing here?\n";
    } 
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "King screams in RAGE: DIEEEEE!\n";
    }
    load_chat(20, chat_str);
    load_a_chat(15, a_chat_str);
 
    money = clone_object("obj/money");
    call_other(money, "set_money", random(10)+10);
    move_object(money, this_object());
 
    armour = clone_object("/wizards/morgoth/cannibal/item/necklace");
    move_object(armour, this_object());
    init_command("wear necklace");
 
    weapon = clone_object("/wizards/morgoth/cannibal/item/sword"); 
    move_object(weapon, this_object());
    init_command("wield sword");
}
