inherit "obj/monster";
reset(arg) {
    object armour;
    string str;
    string chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(65);
   set_con(query_con()*6); 
   set_str(query_str()*2);
    set_max_hp(query_hp()*3);
    set_name("gardener");
    set_alias("elvar");
    set_short("Elvar the beautiful gardener");

    set_long("This young and beautiful gardener is examining some herbs.\n"+ 
             "She handles plants skilfully. The clothes she is wearing are\n"+ 
             "all colored in dark green. Her eyes are dark green and she has\n"+ 
             "a short red hair.\n"); 


    set_al(40);
    set_race("human");
        set_aggressive(0);
       set_gender(2);

    set_log();
    armour = clone_object("/wizards/luminarc/wizcastle/armours/gglove");
    move_object(armour, this_object());
    init_command("wear gloves");
    armour = clone_object("/wizards/luminarc/wizcastle/armours/gboots");
    move_object(armour, this_object());
    init_command("wear boots");

    if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] = "Elvar says: 'Do not distrub me. I need to examine these herbs'\n";
        chat_str[1] = "Elvar says: 'I love these plants!'\n";
        }
load_chat(2, chat_str);
}





