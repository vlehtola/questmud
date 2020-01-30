inherit "obj/monster";

reset(arg) {
    string chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_race("human");
    set_gender(1);
    call_other(this_object(), "set_level", 30);
    call_other(this_object(), "set_name", "monk");
    call_other(this_object(), "set_alias", "Monk");
    call_other(this_object(), "set_short", "A monk listening to the preaching.");
    call_other(this_object(), "set_long", "A monk clad in brown robes listening to the preaching.\n");
    call_other(this_object(), "set_al", 8);
    call_other(this_object(), "set_aggressive", 0);

   chat_str = allocate(2);
   chat_str[0] ="The monk scratches his nose idly.\n";
   chat_str[1] ="The monk doses off for a moment.\n";
   load_chat(10, chat_str); 

}
