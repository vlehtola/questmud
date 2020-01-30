inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    ::reset(arg);
    if (arg) { return; }
    set_level(18);
    set_name("zephaniah");
    set_alias("armenian");
    set_gender(1);
    set_short("Zephaniah, an armenian of the city of Jerusalem");
    set_long("Zephaniah is a man that has seen many things. He\n"+    
             "has a long beard and he twirls his finger around as\n"+
             "if he was impatient or something. His clothing is very poor.\n");
    set_al(3);
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] ="Zephaniah gurgles with his last words: 'Water, please bring me water.'\n";
        chat_str[1] ="The citizen sits up and begs for water.\n";
        chat_str[2] ="Zephaniah pants and swipes sweat of his face.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "The armenian says: I prefer to die in battle then of thirst\n";
    }
    load_chat(15, chat_str);
    load_a_chat(20, a_chat_str);

}

catch_tell(str) {
    string giver,item,tmp;
    object ob, item_ob;
    if (!str) { return 1; }
    if (sscanf(str, "%s gives %s to %s", giver, item, tmp) == 3) {
      ob = present(lower_case(giver),environment(this_object()));
      if (!ob) { return; }
      item_ob = present("flask", this_object());
      if (!item_ob) { return; }
      if (item_ob->short() != "A full flask of clear water") {
         tell_object(ob, "The man shots 'Take this waste away "+
                "from me.'\n");
         tell_object(ob, "The man gives your "+capitalize(item)+
                " back to you.\n");
         move_object(present(item,this_object()), ob);
         return;
      }
      if (ob && item_ob && item_ob->short() == "A full flask of clear water" &&
                !ob->query_quests("Zephaniah")) {
         tell_object(ob, "You complete the quest of helping Zephaniah.\n");
         call_other(ob, "set_quest", "Zephaniah", 15);
      }
      destruct(item_ob);
    }
}
