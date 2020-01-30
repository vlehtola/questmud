inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object armour, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(13);
    set_name("sailor");
    set_alias("sailor");
    set_short("A sailor");
    set_long("This man seems to be pretty old. He has white beard, black eyepatch and a red scarf\n"+
                    "tied around his head. He is a true sailor.\n");
    set_al(0);
    set_move_at_random(0);
    set_aggressive(0);
if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] ="Sailor grins evilly.\n";
        chat_str[1] ="Sailor whispers to you: I want to mutiny!\n";
        chat_str[2] ="Sailor says: I have been in this ship too long.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Sailor grunts 'So you want some action eh?'\n";
    }
    load_chat(20, chat_str);
    load_a_chat(20, a_chat_str);
}
