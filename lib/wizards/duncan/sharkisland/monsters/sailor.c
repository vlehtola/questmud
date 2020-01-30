inherit "obj/monster";
reset(arg) {
    string chat_str, a_chat_str;
    ::reset(arg);
    if (arg) { return; }
    set_level(40);
    set_alias("sailor");
    set_short("A sad and old sailor looking for trees");
    set_long("A sad looking sailor is here looking for trees to his boat. He's fat, short\n"+ 
             "and old. He has a wooden right leg because he lost his right leg to a shark.\n"+ 
             "His skin is brown, thanks to the sun.\n");
    
    set_al(40);
    set_gender(1);
    set_race("human");
    set_aggressive(0);


    if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] =
"Sailor says: 'I have to build a new boat!'\n";
        chat_str[1] =
"The sailor starts to saw a huge tree.\n";

    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "sailor says: I'll kick you with my wooden leg!'\n";
    }
    load_chat(3, chat_str);
    load_a_chat(3, a_chat_str);
   }









