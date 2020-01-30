inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object armour, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(30);
    set_name("captain");
    set_alias("captain");
    set_short("A murky looking captain called 'Black Beard");
    set_long("This is the captain of this ship. His face is full of scars and his eye is patched\n"+                     "with black eyepatch. He looks very mean and skillful.\n");
    set_al(-5);
    set_move_at_random(0);
    set_aggressive(0);
if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] ="Captain looks at you carefully.\n";
        chat_str[1] ="Captain burps.\n";
        chat_str[2] ="Captain says 'My compass is broken, can you fix it?'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Captain screams 'MUTINY!'\n";
    }
    load_chat(20, chat_str);
    load_a_chat(20, a_chat_str);
 armour = clone_object("/wizards/aarrgh/ship/patch");
    move_object(armour, this_object());
init_command("wear patch");
}
