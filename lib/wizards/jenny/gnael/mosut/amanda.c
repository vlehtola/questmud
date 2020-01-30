inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    ::reset(arg);
    if (arg) { return; }
    set_level(45);
    set_gender(2);
    set_race("human");
    set_name("amanda");
    set_alias("woman");
    set_alt_alias("guy");
    set_short("Amanda, the lady of the mansion");
    set_long("Amanda is about 40 years old woman and she is\n" +
             "the owner's wife. She has long blonde hair and green\n" +
             "mysterious looking eyes. She is wearing a beautiful\n" +
             "blue dress, but she seems to be worried about something.\n");
    set_al(0);
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] ="Amanda says: 'Where could my silver necklace be?'\n";
        chat_str[1] ="Amanda says: 'I hope no one has stolen it!'\n";
        chat_str[2] ="Amanda says: 'If my husband finds out i lost it I'm doomed!'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(2);
        a_chat_str[0] = "Amanda says: 'I must find my necklace!!'\n";
        a_chat_str[1] = "Amanda says: 'I left it on my desk, but now..'\n";
    }
    load_chat(20, chat_str);
    load_a_chat(20, a_chat_str);

}


catch_tell(str) {
    string giver,item,tmp;
    object ob, item_ob;
::catch_tell(str);
    if (!str) { return 1; }
    if (sscanf(str, "%s gives %s to %s", giver, item, tmp) == 3) {
      ob = present(lower_case(giver),environment(this_object()));
      if (!ob) { return; }

      item_ob = present("necklace", this_object());

      if (!item_ob) { return; }
      if (ob && item_ob != present("necklace",this_object())) {
         tell_object(ob, "Amanda says: 'This is not my necklace!'\n");
         tell_object(ob, "Amanda gives "+capitalize(item)+
                " back to you.\n");
         move_object(item_ob, ob);
         return;
      }

      if (ob && item_ob == present("necklace",this_object()))
        {
         tell_object(ob, "Amanda gives you a letter.\n");
         tell_room(environment(this_object()),
                "Amanda gives "+capitalize(this_player()->query_name())+
                " a letter.\n" , ({ this_player() }) );
         move_object(clone_object("/wizards/jenny/gnael/rojut/letter.c"),this_player());
         write("Amanda says: 'Thank you so much! Now my husband never finds out i lost this!'\n");
         write("Amanda says: 'As a reward I'll give you this letter, take it to mayor\n");
         this_player()->set_quest("It begins");
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
