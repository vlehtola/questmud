inherit "obj/monster";
reset(arg) {
        string chat_str;
        ::reset(arg);
        if(arg) {return; }
        set_name("fisherman");
        set_alias("man");
        set_race("human");
        set_level(1+random(2));
        set_gender(1);
        set_al(-5);
        set_short("A short fisherman");
        set_long("He looks quite strong and agile. Maybe it's because of the hard\n"+
                 "work, what the fishermen must do for their living. He has big beard and pipe\n"+
                 "in his mouth.\n");
                 if (!chat_str) {
                                chat_str = allocate(3);
                                chat_str[0] = "Smoke rises from the fishermans pipe.\n";
                                chat_str[1] = "Fisherman taps his pipe.\n";
                                chat_str[2] = "Fisherman says: 'Nothing beats a good tobacco after hard work.'\n";
                         }
                         load_chat(3, chat_str);

}
