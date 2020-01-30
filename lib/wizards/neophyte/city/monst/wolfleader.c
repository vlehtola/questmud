inherit "obj/monster";
reset(arg) {
        object hide;
        string chat_str;
                ::reset(arg);
                if(arg) {return; }
                set_name("wolf");
                set_alias("melbo");
        set_level(35);
            set_max_hp(query_hp()+10000);
            set_hp(query_max_hp());

    set_short("Melbo the ancient wolf");
    set_long("The fur on wolf looks like pure silver. This proud looking\n"+
             "wolf is actually a ancient silver wolf. The wolf looks quite\n"+
             "intelligent and doesn't seem to be aggressive.\n");
    set_animal();
    set_aggressive(0);
    hide = clone_object("/wizards/neophyte/city/obj/wolfhide.c");
    move_object(hide, this_object());

    if (!chat_str) {
        chat_str = allocate(5);
        chat_str[0] = "Wolf growls angrily.\n";
        chat_str[1] = "Wolf lays down next to the throne.\n";
        chat_str[2] = "Wolf stands up and stretch a little.\n";
}

    load_chat(1, chat_str);
}
