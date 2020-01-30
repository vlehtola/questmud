inherit "obj/monster"; 
 
reset(arg) {
    string chat_str, a_chat_str;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 11);
    call_other(this_object(), "set_name", "citizen");
    call_other(this_object(), "set_alias", "citizen");
    call_other(this_object(), "set_short", "A peaceful citizen of Jericho");    
    call_other(this_object(), "set_long", "This citizen looks strangely at you.\n" +
                                          "Maybe he hasn't seen too many wierdoes like you before.\n" +
                                          "Leave the poor guy alone.\n");
   call_other(this_object(), "set_al", 10);
  call_other(this_object(), "set_aggressive", 0);
    if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] =
          "Citizen mumbles something peculiar.\n";
        chat_str[1] =
          "Citizen says: se, nne, ndd\n";
        
  }                
 if (!a_chat_str) {
   a_chat_str = allocate(1);
   a_chat_str[0] = "citizen kicks the dirt and looks confused.\n";
   }
    load_chat(5, chat_str);
    load_a_chat(21, a_chat_str);
 
 
 
    
}

