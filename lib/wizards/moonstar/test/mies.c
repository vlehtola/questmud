inherit "obj/monster";

reset(arg) {
    object money;
    string chat_str, a_chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_race("human");
    set_level(25);
    set_alias("man");
    set_name("Marx");
    set_short("Old and filthy looking man is sitting here");
      set_long("Small man is muttering something. He looks like\n"+
               "he has been here forever and he is still looking for\n"+
               "something important.\n");
    set_al(-5);
    set_gender(1);
  if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] ="Man mutters: 'I need my cap..'\n";
        chat_str[1] ="Man says: 'Please go and find it..'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Man says: 'Channelor will banish you!'\n";
    }
    load_chat(3, chat_str);
    load_a_chat(3, a_chat_str);
}
catch_tell(str) {
   string tmp1,tmp2;
   object ob;
   object evilman;
   ::catch_tell(str);
   if (sscanf(str, "%s gives %s to you.", tmp1, tmp2) == 2) {
    ob = present("cap", this_object());
    if (ob && this_player()->query_name() == tmp1 && !ob->query_no_save()) {
    write("Man says: 'Thank you very much, now i can be free!\n");
    write("Man wears cap and suddenly he is totally different person!\n");
    write("for a second you see two men but suddenly they are one.");
    this_player()->set_quest("Find channelors husband Marx");
                evilman = clone_object("/wizards/moonstar/areas/sewers/monsut/evilman.c");
                move_object(evilman, environment(this_object()));
call_out( "delay_dest" , 0 , this_object() );
  }
 }
}

int delay_dest(object obj)
{
destruct(obj);
return 1;
}
