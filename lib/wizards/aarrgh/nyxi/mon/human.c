inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object armour, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(1);
    set_name("human");
    set_alias("human");
set_str(98);
    set_short("A weak human in chains");
    set_long("This man looks tortured and weak from the lack of food.\n"+
	"He is attached to the wall with chains.\n");
    set_al(50);
    set_move_at_random(0);

    set_aggressive(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] ="Human cries: They are.. going to.. sacrifice me.\n";
        chat_str[1] ="Human whispers to you: Try..to...b*cough*low..the..m.s...\n";
        chat_str[2] ="Human says: These.. chains.. hurt..my..hands.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Human screams in agony!\n";
    }
    load_chat(20, chat_str);
    load_a_chat(20, a_chat_str);
}
