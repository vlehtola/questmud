inherit "obj/monster";
 
    reset(arg) {
    string chat_str, a_chat_str;
    object money;
        ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 11);
    call_other(this_object(), "set_name", "dwarf");
    call_other(this_object(), "set_alias", "gully");
    call_other(this_object(), "set_short", "A typical gully dwarf");
    call_other(this_object(), "set_long", "'This looks like a normal scarecrow.\n" +
                                          "The gully dwarf is surely the ugliest thing you've ever seen.\n"+
                                          "It doesn't seem to be of any opinion to your entering.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);

     if (!chat_str) {
        chat_str = allocate(5);
        chat_str[0] =
          "There secret way to bosses is.\n";
        chat_str[1] =
          "You rat need to secret way.\n";
        chat_str[2] =
          "Stick rat in hole to open way to big bosses.\n";
        chat_str[3]=
          "You want me to lead to bosses?\n";
        chat_str[4]=
          "Gully dwarf looks at you ridiculously.\n";
 
}
     if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Why you do that? Not want secret way?\n";
  }                  
    load_chat(10, chat_str);
    load_a_chat(15, a_chat_str);
 
 
    money = clone_object("obj/money");
    call_other(money, "set_money", random(5000)+1000);
    move_object(money, this_object());
 
}

