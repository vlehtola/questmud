inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    ::reset(arg);
    if (arg) { return; }
    set_level(10);
    set_gender(1);
    set_race("human");
    set_name("man");
    set_alias("man");
    set_alt_alias("guy");
    set_short("A weird looking guy is here scratching the wall");
    set_long("This strange looking man has bloody fingers and he still \n" +
             "just keeps scratching the wall with his fingers. Either \n" +
             "he is stupid or just crazy, who knows. He is mumbling \n" +
             "something, but you can't hear him very well. \n");
    set_al(0);
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] ="Man mumbles: if....just...find...'\n";
        chat_str[1] ="Man mumbles: ...Can't....need....sharp...'\n";
        chat_str[2] ="Man mumbles: ...finger's...too...big...grr...need...'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(2);
        a_chat_str[0] = "Man mumbles: Puuh...I'm so tired...'\n";
        a_chat_str[1] = "Man mumbles: .......'\n";
    }
    load_chat(20, chat_str);
    load_a_chat(20, a_chat_str);

}


//Fixed by Rag
catch_tell(str) {
    string giver,item,tmp;
    object ob, item_ob;
::catch_tell(str);
    if (!str) { return 1; }
    if (sscanf(str, "%s gives %s to %s", giver, item, tmp) == 3) {
      ob = present(lower_case(giver),environment(this_object()));
      if (!ob) { return; }

      item_ob = present("knife", this_object());

      if (!item_ob) { return; }
      if (ob && item_ob != present("chef_knife",this_object())) {
         tell_object(ob, "Man mumbles: 'I don't need this'\n");
         tell_object(ob, "Man gives "+capitalize(item)+
                " back to you.\n");
         move_object(item_ob, ob);
         return;
      }

      if (ob && item_ob == present("chef_knife",this_object()))
        {
         tell_object(ob, "Man gives you a letter.\n");
         tell_room(environment(this_object()),
                "Man gives "+capitalize(this_player()->query_name())+
                " a letter.\n" , ({ this_player() }) );
         move_object(clone_object("/wizards/jenny/linnake/rojut/letter.c"),this_player());
         write("Man mumbles: Ah thank you, now I finally got my ring out of\n");
         write("that hole. Take this letter to August and he might reward you.\n");
         call_out( "delay_dest" , 2 , this_object() );
       return 1;
 }
    }
}

/*************************************/

int delay_dest(object obj)
{
destruct(obj);
return 1;
}
