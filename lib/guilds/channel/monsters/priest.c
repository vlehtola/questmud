inherit "obj/monster";
   
    string chat_str,a_chat_str;

reset(arg) {


    ::reset(arg);
    if(arg) { return; }

    set_level(4+random(2));
    set_name("priest");
    set_race("human");
    set_short("A proud priest reading his holy book");
    set_long("A priest reading his holy book intensely and mumbling some holy words.\n"+
             "He is very clean, he obviously takes good care of himself to please his\n"+
             "God.\n");

    set_al(50);
    set_aggressive(0);
    set_al_aggr(151);
    set_gender(1);
 
     if (!chat_str) {
        chat_str = allocate(3);
    chat_str[0] = "The priest reads his holy book sentimentally.\n";
    chat_str[1] = "The priest says with a calm voice 'Cyral can help you, it is\n"+
                  "not too late.'\n";
    chat_str[2] = "The priest raises his head high and mumbles some holy words.\n";             
       }
     if (!a_chat_str) {
        a_chat_str = allocate(2);
   a_chat_str[0] = "The priest curses you.\n";
   a_chat_str[1] = "The priest screams in fury 'Cyral will punish you for your sins!'\n";
                
                 
       }
    load_chat(2, chat_str);
    load_a_chat(7, a_chat_str);





 }
