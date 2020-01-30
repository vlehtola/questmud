inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object weapon;
    ::reset(arg);
    if(arg) { return; }
    set_level(15);
    set_gender(1);
    set_race("human");
    set_name("supervisor");
    set_short("The supervisor is hiding behind a ham");
    set_long("The supervisor's fine clothes are practically in rags.\n"+
             "He looks at you fearfully.\n");
    set_al(8); 
if (!chat_str) {
        chat_str = allocate(2); 
        chat_str[0] =
"The supervisor gasps:'We were trading with the Black Circle mercenary company when we discovered the frozen area. We naturally informed them of our find and they paid back by killin everybody.'\n"; 
chat_str[1] =
  "'Most of us were trapped behind a rockfall on this level', the supervisor says.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "The supervisor brandishes his sword with obvious skill.\n";
    }
    load_chat(10, chat_str);
    load_a_chat(20, a_chat_str);
    
    weapon = clone_object("/wizards/tiergon/eq/thiefblade");
    move_object(weapon, this_object());
    init_command("wield sword");
}
