inherit "obj/monster";
string chat_str, a_chat_str;

reset(arg) {
    ::reset(arg);
    if (arg) { return; }
     set_name("ninni");
     set_alias("Ninni");
     set_race("sprite");
     set_mage(0);
     set_gender(2);     
     set_level(100);
     set_exp(100000000);
     set_str(query_str() + 123);
     set_dex(query_dex() + 123);
     set_con(query_con() + 123);
     set_int(query_int() + 123);
     set_wis(query_wis() + 123);
     set_resists("cold", 70 + random(13));
     set_resists("fire", 70 + random(13));
     set_resists("electric", 70 + random(13)); 
     set_log();
     set_short("Cute young sprite called 'Ninni' (flying)");
     set_long("Cute female sprite dressed in red.\n");
        
         if (!chat_str) {
         chat_str = allocate(1);
         chat_str[0] = "Ninni flies to you and whispers something to your ear.\n";
    }
         if (!a_chat_str) {
         a_chat_str = allocate(1);
         a_chat_str[0] = "Ninni sobs 'Why are you doing this to me!'\n";
    }
    
    load_chat(4, chat_str);
    load_a_chat(6, a_chat_str);
}
