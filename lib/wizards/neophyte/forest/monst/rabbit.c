inherit "obj/monster";
reset(arg) {
        string chat_str;
        ::reset(arg);
        if(arg) {return; }
        set_name("rabbit");
        set_alias("white");
        set_level(1);
        set_gender(0);
        set_al(0);
        set_animal(1);
        set_short("A rabbit");
        set_long("It has white, flurry fur and little dangled ears.\n"+
                 "The rabbit is happy. These fields offer everything it needs\n"+
                 "in its simple, free life.\n");
                 if (!chat_str) {
                                chat_str = allocate(1);
                                chat_str[0] = "Rabbit jumps happily around you.\n";
                         }
                         load_chat(3, chat_str);

}
