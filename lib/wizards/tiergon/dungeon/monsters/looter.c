inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object weapon;
    object armour;
    ::reset(arg);
    if(arg) { return; }
    set_level(14);
    set_gender(2);
    set_race("human");
    set_name("looter");
    set_alias("woman");
    set_short("A beautiful woman looting the room");
    set_long("The woman is stunningly beautiful brunette. The size of her ... eyes amazes you.\n");
    set_al(-11); 
if (!chat_str) {
        chat_str = allocate(2); 
        chat_str[0] =
"In spite of your best attempts the woman completely ignores you and calmly continues looting the room.\n";
chat_str[1] =
  "You admire the woman's graceful way of stealing.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "The woman charges you screaming like a banshee.\n";
    }
    load_chat(10, chat_str);
    load_a_chat(20, a_chat_str);
    
    weapon = clone_object("/wizards/tiergon/eq/thiefblade");
    move_object(weapon, this_object());
    init_command("wield sword");

    armour = clone_object("/wizards/tiergon/eq/larmour");
    move_object(armour, this_object());
    init_command("wear armour");
}
