inherit "obj/monster";
reset(arg) {
    string chat_str, a_chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(random(5)+20);
    set_name("chicken");
    set_short("A chicken pecking the ground");
    set_long("A white chicken but some of the feathers are quite dirty.\n"+
             "It is walking on the ground and pecking it.\n");
    set_gender(0);
    set_animal();
        if (!chat_str) {
                chat_str = allocate(1);
                chat_str[0] = "Chicken starts to peck the ground.\n";
            }
            if (!a_chat_str) {
                a_chat_str = allocate(1);
                a_chat_str[0] = "Chicken hits you with his beak.\n";
            }
            load_chat(3, chat_str);
            load_a_chat(3, a_chat_str);
 }
