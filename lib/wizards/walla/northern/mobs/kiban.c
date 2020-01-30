inherit "obj/monster";
 
reset(arg) {
    string chat_str, a_chat_str;
    object axe;
    ::reset(arg);
    if(arg) { return; }
    set_level(50+random(4));
    set_name("kiban-bazad");
    set_alias("dwarf");
    set_alias("guardian");
    set_short("Kiban-Bazad, guardian of the flag");
    set_long("Before you stands a bearded fellow, just over 5 feet tall, and stout\n"+
             "as a barrel. The good man's beard is over one foot long, and it is tied\n"+
             "to a knot at the end. Kiban-Bazad has for mission to guard the flag.\n");
    set_race("dwarf");
    set_gender(1);
    set_al(-8);
  
 
    axe = clone_object("/wizards/walla/northern/stuph/basic_axe");
    move_object(axe, this_object());
    init_command("wield axe");
 
    if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Kiban-Bazad moves around just a little bit.\n";
        chat_str[1] =
          "Kiban-Bazad whispers: 'I have been placed here to salute the flag'.\n";
        chat_str[2] =
          "Kiban-Bazad whispers: 'If the flag falls, the castle falls.'\n";
 
   }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Kiban-Bazad: 'Guards, at me, the flag is falling!!'.\n";
    }
       load_chat(3, chat_str);
       load_a_chat(3, a_chat_str);
 
}
 
