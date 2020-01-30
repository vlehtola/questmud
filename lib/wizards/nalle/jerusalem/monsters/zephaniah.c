inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    ::reset(arg);
    if (arg) { return; }
    set_level(18);
    set_race("human");
    set_exp(70981);
    set_name("zephaniah");
    set_alias("man");
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
        chat_str[0] ="Zephaniah gurgles 'What would I not do for some of the famed Holy Water!'\n";
        chat_str[1] ="The man states 'Despite my poor appearance, I could reward you well!'\n";
        chat_str[2] ="Zephaniah complains about his aching bones.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "The man says 'I prefer to die in battle then of age.'\n";
    }
    load_chat(5, chat_str);
    load_a_chat(20, a_chat_str);

}

catch_tell(str) {
    string giver,item,tmp;
    object ob, item_ob;
    if (!str) { return 1; }
    if (sscanf(str, "%s gives %s to you.", giver, item) == 2) {
      ob = present(lower_case(giver),environment(this_object()));
      if (!ob) { return; }
      item_ob = present("flask", this_object());
      if (!item_ob) { return; }
      if (item_ob->short() != "A full flask of clear water" && !item_ob->query_no_save()) {
         tell_object(ob, "The man shots 'Take this waste away "+
                "from me.'\n");
         tell_object(ob, "The man gives your "+capitalize(item)+
                " back to you.\n");
         move_object(present(item,this_object()), ob);
         return;
      }
      if (ob && item_ob && item_ob->short() == "A full flask of clear water" &&
                !ob->query_quests("Give Zephaniah a flask of Holy Water"))
{
         tell_object(ob, "You complete the quest of helping Zephaniah.\n");
         call_other(ob, "set_quest", "Give Zephaniah a flask of Holy Water");
      } else { write("You have already completed this quest.\n"); }
      destruct(item_ob);
      return 1;
    }
}
