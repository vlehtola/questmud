inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    ::reset(arg);
    if (arg) { return; }
    set_level(18);
    set_name("Lady");
    set_alias("lady");
    set_race("human");
    set_gender(2);
    set_short("A lady in distress");
    set_long("This lady seems quite distressed.\n");
    set_al(10);
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] ="The lady whines: That evil man took my cat and climbed out of the window!\n";
        chat_str[1] ="The lady whimpers: Please get my cat back.\n";
        chat_str[2] ="The lady sobs: My kitten must still be up there in the tower.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "The lady shrieks: Swine! Pig! All men are alike!\n";
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
      item_ob = present("kitten", this_object());
      if (!item_ob) { return; }
      if(item_ob->query_no_save()) return;
      if (item_ob->short() != "A cute little kitten") {
         tell_object(ob, "The lady sighs: 'This does not comfort me "+
                "at all.'\n");
         tell_object(ob, "The lady gives the "+capitalize(item)+
                " back to you.\n");
         move_object(present(item,this_object()), ob);
         return;
      }
      if (ob && item_ob && item_ob->short() == "A cute little kitten" &&
                !ob->query_quests("Rescue the little kitten")) {
         tell_object(ob, "You complete the 'Rescue the little kitten' quest.\n");
         call_other(ob, "set_quest", "Rescue the little kitten");
      }
      destruct(item_ob);
    }
}
