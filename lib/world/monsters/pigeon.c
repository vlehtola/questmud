inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(12);
    set_name("pigeon");
    set_alias("pigeon");
    set_short("A HUGE black pigeon from HELL"); 
    set_long("A HUGE black pigeon is here avenging his relatives deaths.\n");
    set_al(-50);
    set_aggressive(1);
    set_animal(1);
            
    if (!a_chat_str) {
        a_chat_str = allocate(3);
        a_chat_str[0] =
              "Black pigeon groars: Did YOU kill my brother!?!\n";
        a_chat_str[1] =
              "Black pigeon groars: Die you pigeon killer!\n";
        a_chat_str[2] =
              "Black pigeon groars: I'm here to avenge for my brothers\n";
    }                
    
    load_a_chat(30, a_chat_str);
}

