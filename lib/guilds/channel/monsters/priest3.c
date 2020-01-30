inherit "obj/monster";
   
    string chat_str;

reset(arg) {


    ::reset(arg);
    if(arg) { return; }

    set_level(4+random(2));
    set_name("priest");
    set_race("human");
    set_short("A drunken priest");
    set_long("A young priest hiding from his work. He is extremely drunk and\n"+
             "it a miracle that he is still standing.\n");


    set_al(50);
    set_aggressive(0);
    set_al_aggr(400);
    set_gender(1);
 
     if (!chat_str) {
        chat_str = allocate(2);
    chat_str[0] = "The drunken priest stumbles.\n";
    chat_str[1] = "The priest says 'I'm not drunk, just feeling a bit dizzy!'\n";
           
       }

       load_chat(2, chat_str);






 }
