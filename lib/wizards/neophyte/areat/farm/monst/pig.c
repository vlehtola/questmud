inherit "obj/monster";
reset(arg) {
    int i;
    string str, chat_str, a_chat_str;
    ::reset(arg);
    if(arg) { return; }
    i = random(3);
    if(i==0) str = "A dirty pig";
    if(i==1) str = "A fat looking pig";
    if(i==2) str = "A pig is taking mud bath";

    set_level(random(5)+20);
    set_name("pig");
    set_short(""+str+"");
    set_long("Pigs skin is almost totally covered with mud. Only some pink parts\n"+
             "of its skin are in sight. It has a tiny pink tail and a happy look in\n"+
             "its face.\n");
    set_gender(0);
    set_animal();
        if (!chat_str) {
                chat_str = allocate(2);
                chat_str[0] =
        "Pig goes 'Oink Oink'.\n";
                chat_str[1] =
        "Pig rolls over in mud.\n";
            }
            if (!a_chat_str) {
                a_chat_str = allocate(1);
                a_chat_str[0] = "Pig screams.\n";
            }
            load_chat(3, chat_str);
            load_a_chat(3, a_chat_str);

 }
