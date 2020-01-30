inherit "obj/monster";
reset(arg) {
        object gdagger;
        string chat_str;
                ::reset(arg);
                if(arg) {return; }
                set_name("xiakin");
                set_alias("king");
        set_level(50+random(10));
        set_int(query_int()*2);
            set_hp(query_max_hp()*2);
            set_max_hp(query_hp()*2);

    set_short("Xiakin the goblin king");
    set_long("This old looking goblin is a king of the goblins.\n"+
             "He has a grey skin and a quite large head. The king\n"+
             "dosent look like a average goblin but bigger, stronger\n"+
             "and more wiser.\n");
    set_aggressive(0);
    set_gender(1);
    set_skill("stab", 100);
    set_skill("double stab", 70);
    set_skill("stunning touch", 100);
    set_log();
        gdagger = clone_object("/wizards/neophyte/city/eq/gdagger.c");
                move_object(gdagger, this_object());
            init_command("wield dagger");
    if (!chat_str) {
        chat_str = allocate(5);
        chat_str[0] = "Xiakin says: 'Could you help a little?'\n";
        chat_str[1] = "Xiakin says: 'I have little task for you.'\n";
        chat_str[2] = "Xiakin puuhs tiredly.\n";
}

    load_chat(1, chat_str);
}

ask_question(str) {
        if(str == "task") {
                say("King says: 'I will need a new sheepskin.\n");
                return 1;
        }
        if(str == "skin" || "sheepskin") {
                say("King says: 'I have heard that the old woman somewhere will make a great ones.\n");
                say("King hmms and says: 'Yes, that is what i want so go get it for me.\n");
                return 1;
        }
        write("King says: 'I don't know anything about that'.\n");
        return 1;
}

catch_tell(str) {
        string tmp1, tmp2, chat_str;
           object ob;
        ::catch_tell(str);
  if (sscanf(str, "%s gives %s to you.", tmp1, tmp2) == 2) {
    ob = present("lampaan_talja", this_object());
    if (ob && this_player()->query_name() == tmp1) {
                if(this_player()->query_quests("Bring sheephide to goblin")) {
                        write("You have allready helped me.\n");
                        return 1;
                }
                        write("King says: 'Thank you very much.'\n");
                        this_player()->set_quest("Bring sheephide to goblin");
                        destruct(ob);
                        return 1;

  }
 }
}
