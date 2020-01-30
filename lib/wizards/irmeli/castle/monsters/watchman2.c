inherit "obj/monster";
reset(arg) {
    object weapon,weapon2;
    string chat_str, a_chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(43);
set_name("watchman");
set_alias("man");
set_short("A strong and proud watchman standing in the guardhouse");
    set_long("The watchman looks strong and proud. He is standing on his guardhouse. He is\n"
             "watching in the horizon waiting to his shift to end. The guardhouse watchmen\n"
              "are rumoured to have very long shifts. \n");
    set_al(0); 
    set_aggressive(0);
set_race("human");
set_gender(1);
set_init_ob(this_object());
set_move_at_random(0);

    weapon = clone_object("/wizards/irmeli/castle/eq/sword.c");
    move_object(weapon, this_object());
    init_command("wield sword");

    weapon = clone_object("/wizards/irmeli/castle/eq/shield.c");
    move_object(weapon, this_object());
    init_command("wield shield");

 if (!chat_str) {
        chat_str = allocate(1);
        chat_str[0] = "Watchman says: 'The predicted flood is nonsense!'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Watchman says: 'You'll regret this!'\n";

    }
    load_chat(1, chat_str); 
    load_a_chat(1, a_chat_str);
}
