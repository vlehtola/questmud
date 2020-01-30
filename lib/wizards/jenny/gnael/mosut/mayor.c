inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    ::reset(arg);
    if (arg) { return; }
    set_level(40);
    set_gender(1);
    set_race("human");
    set_name("harald");
    set_alias("mayor");
    set_alt_alias("man");
    set_short("Harald Higledilodrim, the mayor of Gnael");
    set_long("Harald is about sixtyfive years old man who\n" +
             "has been the mayor for almost thirty years now. He has\n"+
             "short gray hair and he is wearing a clean mayor outfit\n" +
             "with top hat and nice looking walking stick.\n");
    set_al(0);
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] ="Mayor says: 'Yes, I have the key to the locked door'\n";
        chat_str[1] ="Mayor says: 'I will give the key only to a person who earns my trust'\n";
        chat_str[2] ="Mayor says: 'I really hate that Mondasa'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(2);
        a_chat_str[0] = "Mayor says: 'Why, oh why'\n";
        a_chat_str[1] = "Mayor says: 'Poor city..'\n";
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

      item_ob = present("letter", this_object());

      if (!item_ob) { return; }
      if (ob && item_ob != present("letter",this_object())) {
         tell_object(ob, "Mayor says: 'I don't need this'\n");
         tell_object(ob, "Mayor gives "+capitalize(item)+
                " back to you.\n");
         move_object(item_ob, ob);
         return;
      }

      if (ob && item_ob == present("letter",this_object()))
        {
         tell_object(ob, "Mayor gives you a key.\n");
         tell_room(environment(this_object()),
                "Mayor gives "+capitalize(this_player()->query_name())+
                " a key.\n" , ({ this_player() }) );
         move_object(clone_object("/wizards/jenny/gnael/rojut/well_key.c"),this_player());
         write("Mayor says: 'Ok, you have earned my trust. Here is the key to the locked door in well'\n");
         write("Mayor says: 'If you really can win Mondasa, you will become a hero!\n");
         this_player()->set_quest("Closing the goal");
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
