inherit "obj/monster";
 
reset(arg) {
    string chat_str, a_chat_str;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 8);
    call_other(this_object(), "set_name", "bum");
    call_other(this_object(), "set_alias", "man");
    call_other(this_object(), "set_short", "A huge fat bum");
    call_other(this_object(), "set_long",
"This bum is really huge and angry looking. Maybe you shouldn't\n"+
"give him a reason to attack you.\n");
    call_other(this_object(), "set_al", -10);
    call_other(this_object(), "set_race", "human");
    call_other(this_object(), "set_aggressive", 0);
 
      if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Bum says 'You fucking rich boy!'\n";
        chat_str[1] =
          "Bum farts at your general direction.\n";
        chat_str[2] =
          "Bum says 'This is my kingdom and you are not going anywhere.'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Bum laughs mercilessly!\n";
    }
    load_chat(20, chat_str);
    load_a_chat(15, a_chat_str);
 
}
