inherit "obj/monster";

reset(arg) {
    string chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_gender(0);
    call_other(this_object(), "set_level", 5);
    call_other(this_object(), "set_name", "crow");
    call_other(this_object(), "set_alias", "Crow");
    call_other(this_object(), "set_short", "A black crow, hopping on the ground by the entrance");
    call_other(this_object(), "set_long", "A black crow, fluttering its wings every now and then.\n");
    call_other(this_object(), "set_al", 0);
    call_other(this_object(), "set_aggressive", 0);
    set_animal(1);

   chat_str = allocate(2);
   chat_str[0] ="The crow hops on the ground and screeches loudly.\n";
   chat_str[1] ="The crow glances at you and screeches noisily.\n";
   load_chat(21, chat_str);
}
