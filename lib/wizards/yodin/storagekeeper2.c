inherit "obj/monster";


reset(arg) {
string chat_str, a_chat_str;
    ::reset(arg);
   if (arg)  return;
set_name("keeper");
set_short("A dirty storage keeper.");
set_long("A storage keeper that keeps storage full and clean.\n");
set_level(100);
set_gender(1);
set_alias("human");
set_race("human");
set_mage(1);
   set_al(0);



if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] =
        "Keeper says: 'I have run out of flour.. Could you get some for me?'\n";
        chat_str[1] =
        "Keeper says: 'Please i need more flour so we can make more bread.'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Keeper says: 'I love my job'\n";
    }

    load_chat(3, chat_str);
    load_a_chat(3, a_chat_str);

}

 catch_tell(str) {
    string giver,item,tmp;
    object ob, item_ob;
    if (!str) { return 1; }
    if (sscanf(str, "%s gives %s to %s", giver, item, tmp) == 3) {
      ob = present(lower_case(giver),environment(this_object()));
      if (!ob) { return; }
      if (item_ob->query_real_flour())
      if (!item_ob) { return; }

      if (ob && item_ob && tmp == "you.") {
         tell_object(ob, "Keeper says: 'Thank you very mutch now we can make more bread.'\n");
         tell_object(ob, "You complete the 'Help the baker' quest.\n");
         call_other(ob, "set_quest", "Help the baker");
 destroy_obj( item_ob );
    }
 }
}

destroy_obj( item_ob );
void destroy_obj(object item_ob)
{
 call_out( "destruct", 1, item_ob );
}

