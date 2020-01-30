inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object cloak;
    ::reset(arg);
    if(arg) { return; }
    set_level(5);
    set_name("citizen");
    set_alias("hobbit");
    set_short("A hobbit citizen");
    set_long("A hobbit is lurking around.\n");
    set_gender(1);
    set_race("hobbit");
    set_al(50);
    set_aggressive(0);
    set_move_at_random(2);
    if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Citizen says: Seen my pipe?\n";
        chat_str[1] =
          "Citizen says: Give me my pipe!!\n";
        chat_str[2] =
          "Citizen says: Out of my way!!.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Hobbit shouts: Guards! Help me! Murderers!\n";
    }
    load_chat(40, chat_str);
    load_a_chat(20, a_chat_str);
 

    cloak = clone_object("wizards/bulut/forl/equ/cloak.c");
/*    weapon = clone_object("world/eq/weapons/woodknfe.c");
    move_object(weapon, this_object()); */ 
    move_object(cloak, this_object());
    init_command("wear cloak");
/*    init_command("wield knife"); */
}
