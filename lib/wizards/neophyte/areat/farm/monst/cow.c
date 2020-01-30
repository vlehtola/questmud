inherit "obj/monster";
reset(arg) {
    int i;
    string str, chat_str, a_chat_str;
    ::reset(arg);
    if(arg) { return; }
    i = random(3);
    if(i==0) str = "A black and white cow";
    if(i==1) str = "A brown coloured cow";
    if(i==2) str = "A young cow is eating grass here";

    set_level(random(5)+20);
    set_name("cow");
    set_short(""+str+"");
    set_long("A cow is standing here and eating green grass. It looks quite\n"+
             "large and heavy. It has a pink udder and severals teats on it.\n");
    set_gender(0);
    set_animal();
        if (!chat_str) {
                chat_str = allocate(2);
                chat_str[0] =
        "Cow moo's.\n";
                chat_str[1] =
        "Cow starts to eat grass.\n";
            }
            if (!a_chat_str) {
                a_chat_str = allocate(1);
                a_chat_str[0] = "Cow moo's angrily!\n";
            }
            load_chat(3, chat_str);
            load_a_chat(3, a_chat_str);

 }
