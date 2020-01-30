inherit "obj/monster";

reset(arg) {
    object dress,hat;
    string chat_str, a_chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(13+random(3));
    set_name("widow");
    set_alias("woman");
    set_short("A mourning woman");
    set_long("The woman seems to be weeping for an aquaintance of hers,\n"+
             "that has passed on to happier hunting grounds. She wears\n"+
             "a black dress, and a hat with a veil on it. The veil covers\n"+
             "her face almost completely and the only thing you can see\n"+
             "are a couple of tears, rolling down her face.\n");
    set_race("human");
    set_gender(2);
    set_al(50);
    set_aggressive(0);

    hat = clone_object("/wizards/walla/areas/mg/stuph/widowhat");
    move_object(hat, this_object());
    init_command("wear hat");

    dress = clone_object("/wizards/walla/areas/mg/stuph/widowdress");
    move_object(dress, this_object());
    init_command("wear dress");


    if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Widow sobs a bit and longs for her husband.\n";
        chat_str[1] =
          "Widow bursts out in to a controlled burst of tears.\n";
        chat_str[2] =
          "Widow lowers her head and weeps for her loss.\n";

   }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Widow starts crying uncontrollably.\n";
    }
       load_chat(3, chat_str);
       load_a_chat(3, a_chat_str);

}
