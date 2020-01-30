inherit "obj/monster";
reset(arg) {
    int i;
    string str, chat_str, a_chat_str;
    ::reset(arg);
    if(arg) { return; }
    i = random(3);
    if(i==0) str = "A black stallion";
    if(i==1) str = "A strongly build horse is drinking water";
    if(i==2) str = "A horse is eating hay";

    set_level(random(5)+20);
    set_name("horse");
    set_alias("stallion");
    set_short(""+str+"");
    set_long("The horse looks quite tall and muscular. It has a long, black tail\n"+
             "and mane. Muscles of the horse are huge, maybe because the farmers\n"+
             "are taking good care of the animal.\n");
    set_gender(0);
    set_animal();
        if (!chat_str) {
                chat_str = allocate(2);
                chat_str[0] =
        "Horse eats some hay.\n";
                chat_str[1] =
        "Horse drinks water from the bucket.\n";
            }
            if (!a_chat_str) {
                a_chat_str = allocate(1);
                a_chat_str[0] = "Horse makes some noises.\n";
            }
            load_chat(3, chat_str);
            load_a_chat(3, a_chat_str);

 }
