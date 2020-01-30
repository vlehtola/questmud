inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(3);
    set_name("Sir Oxfern");
    set_alias("oxfern");
    set_race("human");
    set_gender(1);
    set_short("Sir Oxfern the tobacconist");
    set_long("This is Sir Oxfern, a retired tobacconist. He is currently\n" +
             "sitting on his rocking chair and smoking his pipe while\n" +
             "reading the newspaper.\n");
    set_al(10);
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Sir Oxfern adds some more tobacco in his pipe.\n";
        chat_str[1] =
          "The lovely smell of tobacco floats by your nose. \n";
        chat_str[2] =
          "Sir Oxfern glances at your clothing and says: 'I hope your not here to see my daughter, eh?'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Sir Oxfern screams: 'Wilhelm! One of your pupils is bothering me!'\n";
    }
    load_chat(10, chat_str);
    load_a_chat(10, a_chat_str);

}
