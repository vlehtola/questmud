inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object cloak, weapon;
    ::reset(arg);
    if(arg) { return; }
    set_level(8);
set_name("guard");
set_alias("hobbit");
    set_short("A hobbit guard");
    set_long("A hobbit guard is standing here.\n");
    set_al(50);
    set_race("halfling");
    set_aggressive(0);
    set_move_at_random(0);
    set_block_dir("east");
    set_gender(1);
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Hobbit grunts: You will regret this!\n";
    }
    load_chat(40, chat_str);
    load_a_chat(20, a_chat_str);

    cloak = clone_object("wizards/bulut/forl/equ/cloak.c");
    move_object(cloak, this_object());
    weapon = clone_object("wizards/bulut/forl/equ/sword.c");
    move_object(weapon, this_object());
    init_command("wield sword"); 
    init_command("wear cloak");
}
