inherit "obj/monster";
 
reset(arg) {
    string chat_str, a_chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(9+random(6));
    set_name("lookout");
    set_alias("dwarf");
    set_short("A dwarven lookout");
    set_long("Before you stands a bearded fellow, just over 5 feet tall, and stout\n"+
             "as a barrel. The good man's beard is over one foot long, and it is tied\n"+
             "to a knot at the end.\n");
    set_race("dwarf");
    set_gender(1);
    set_al(-8);
  
 
    if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Lookout looks at you and whispers: 'Are you here to kill Khilarbhunaz?'\n";
        chat_str[1] =
          "Lookout whispers: 'Oh, is it you?' and winks twice with his eye.\n";
        chat_str[2] =
          "Lookout whispers: 'I can help you, but I must be sure of who you are'.\n";
 
   }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Kiban-Bazad: 'Guards, at me!!'\n";
    }
       load_chat(3, chat_str);
       load_a_chat(3, a_chat_str);
 
}
 
