inherit "obj/monster";
reset(arg) {
    int i;
    string str, chat_str, a_chat_str;
    ::reset(arg);
    if(arg) { return; }
    i = random(3);
    if(i==0) str = "A drunken man";
    if(i==1) str = "Man sitting in a chair and drinking wine";
    if(i==2) str = "A man staggering around the room";

    set_level(random(5)+20);
    set_name("man");
    set_alias("man");
    set_race("human");
    set_short(""+str+"");
    set_long("A ugly looking man dressed in dirty cloths. He seems to be very\n"+
             "drunk and hes staggering badly.\n");
    set_gender(1);
        if (!chat_str) {
                chat_str = allocate(2);
                chat_str[0] =
        "Man takes a long sip from his wine bottle.\n";
                chat_str[1] =
        "Man 'says Bring me moooore boooze!!' and falls down.\n";
            }
            if (!a_chat_str) {
                a_chat_str = allocate(1);
                a_chat_str[0] = "Man shouts 'Please spare my life!!'\n";
            }
            load_chat(3, chat_str);
            load_a_chat(3, a_chat_str);

 }
