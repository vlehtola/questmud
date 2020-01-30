inherit "obj/monster"; 
 
reset(arg) {
    string chat_str, a_chat_str;  
     object money;
        ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 33);
    call_other(this_object(), "set_name", "Igor");
    call_other(this_object(), "set_alias", "drunkard");
    call_other(this_object(), "set_short", "Igor, the storyteller laughs and laughs again");
    call_other(this_object(), "set_long", "As Igor tells a joke, everyone laughs, perhaps\n" +
                                          "only not to make Igor unhappy because seriously speaking his\n" +
                                          "jokes suck.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);
    set_spell_chance(69, "exs zzt blt");          
    set_skill("cast essence", 69); 
    set_skill("cast electricity", 69);  
    set_skill("cast bolt", 69);    
    set_skill("mastery of electricity", 100);
    
     if (!chat_str) {   
        chat_str = allocate(8);
        chat_str[0] =
          "Igor says: I remember a place like this... Sri Lanka, formerly Ceylon...\n";
        chat_str[1] =
          "Igor says: I got one, Why did NASA kidnapp blondes ? Because they are doing researches on black holes.\n";
        chat_str[2] =
          "Garry Kasparov says: White queen to b5.\n";
        chat_str[3]=
          "Garry Kasparov says: Hey! that's not CheckMate!!\n";
        chat_str[4]=
         "Garry Kasparov says: Watch this, I learned this trick from my master, Vladimir Uljanov.\n";
        chat_str[5]=
         "Garry Kasparov says: Kb6.\n";
        chat_str[6]=
         "Garry Kasparov says: Let's go to the pub and have a shot of Vodka when this is all over.\n";
        chat_str[7]=
         "Garry Kasparov says: Checkmate kamaradskaya.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Garry Kasparov: Hey, my suit! \n";
    }
    load_chat(30, chat_str);
    load_a_chat(15, a_chat_str);


    money = clone_object("obj/money");
    call_other(money, "set_money", random(5000)+1000);
    move_object(money, this_object());
 
}
