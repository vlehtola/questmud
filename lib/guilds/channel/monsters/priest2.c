inherit "obj/monster";
   
    string chat_str,a_chat_str;

reset(arg) {


    ::reset(arg);
    if(arg) { return; }

    set_level(5+random(2));
    set_name("priest");
    set_race("human");
    set_short("A priest writing holy scripts");
    set_long("Old and experienced priest writing holy scripts. His hair is\n"+
             "grey and you wonder if it is because of his age or all the\n"+
             "paper work he has done in the past years.\n");

    set_al(50);
    set_aggressive(0);
    set_al_aggr(151);
    set_gender(1);
 
     if (!chat_str) {
        chat_str = allocate(1);
    chat_str[0] = "The priest thinks for a moment and writes something down.\n";
           
       }
     if (!a_chat_str) {
        a_chat_str = allocate(2);
   a_chat_str[0] = "The priest curses you.\n";
   a_chat_str[1] = "The priest screams in fury 'Cyral will punish you for your sins!'\n";
                
                 
       }
    load_chat(2, chat_str);
    load_a_chat(7, a_chat_str);





 }
