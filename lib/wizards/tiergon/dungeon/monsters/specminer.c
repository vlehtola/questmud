inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(13);
    set_gender(1);
    set_undead(1);
    set_name("spectre");
    set_short("The spectre of a miner");
    set_long("This is the transparent form of a miner\n"+
     "The spectre's face is contorted with absolute rage\n");
    set_al(-21);
    set_aggressive(1); 
    set_block_dir("vault");

if (!chat_str) {
        chat_str = allocate(1); 
        chat_str[0] = "The spectre circles around the room, wailing insanely\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "The spectre curses you to join him hell where he ended up due to his cowardice\n";
    }
    load_chat(10, chat_str);
    load_a_chat(30, a_chat_str);
}
