inherit "obj/monster";
reset(arg) {
    object weapon;
    string chat_str, a_chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(31);
set_name("watchman");
set_alias("man");
set_short("A watchman standing on the castle wall");
    set_long("A watchman looks a bit bored because nothing happens in here. He would give\n"+
             "anything if he could fight with someone, even if it's a small fight. His\n"+ 
             "skin is full of tattoos and perforations.\n");

    set_al(0); 
    set_aggressive(0);
set_race("human");
set_gender(1);
set_init_ob(this_object());
set_move_at_random(0);

    weapon = clone_object("/wizards/irmeli/castle/eq/mace.c");
    move_object(weapon, this_object());
    init_command("wield mace");

    if (!chat_str) {
        chat_str = allocate(1);
        chat_str[0] = "Watchman says: 'The castle walls might collapse soon.'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Watchman says: 'You'll regret this!'\n";

    }
    load_chat(1, chat_str); 
    load_a_chat(1, a_chat_str);
}
