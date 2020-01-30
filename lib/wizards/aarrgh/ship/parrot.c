inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object armour, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(5);
    set_name("parrot");
    set_alias("parrot");
    set_short("A multicoloured and wicked looking parrot.");
    set_long("This parrot seems to be just a ordinary parrot, repeating things what \n"+
        "it has been hearing.\n");
    set_al(50);
    set_move_at_random(0);
    set_aggressive(0);
if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] ="Parrot says 'magnet...magnet'.\n";
        chat_str[1] ="Parrot flaps its wings.\n";
        chat_str[2] ="Parrot says 'damned captain...remove magnet..\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Parrot screams 'Kraaah!\n";
    }
    load_chat(20, chat_str);
    load_a_chat(20, a_chat_str);
}
