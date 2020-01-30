inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(10);
    set_name("paladin");
    set_race("human");
    set_alias("guard");
    set_short("Paladin guarding the forest");
    set_long("This is a young paladin guarding the entrance to the damned forest.\n"+
             "He is slightly armoured and avoids looking in to the direction of\n"+
             "the forest.\n");
    set_al(30);
    set_aggressive(0);
    set_block_dir("enter");
    if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] =
"Paladin says: You don't want to enter the forest.\n";
        chat_str[1] =
"Paladin says: That forest is damned.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(3);
        a_chat_str[0] = "Paladin shouts: I can't let you go there!\n";
        a_chat_str[1] = "Paladin says: You'll only get yourself killed!\n";
        a_chat_str[2] = "Paladin says: Believe me!\n";
    }
    load_chat(20, chat_str); 
    load_a_chat(100, a_chat_str); 

}

