inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(21);
    set_race("human");
    set_gender(1);
    set_name("man");
    set_alias("man");
    set_short("An old man");
    set_long("An old man. He seems sad and burdened by grief.\n");
    set_al(10);
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] ="The man mutters: Why did they have to kill my daughter?\n";
        chat_str[1] ="The man grunts: Oh my poor Layla.\n";
        chat_str[2] ="The man says: If someone would only get me her ring.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "The man roars: So you are a sinner too??? \n";
    }
    load_chat(20, chat_str);
    load_a_chat(20, a_chat_str);

}
catch_tell(str) {
    string giver,item,tmp;
    object ob, item_ob;
    if (!str) { return 1; }
    if (sscanf(str, "%s gives %s to %s", giver, item, tmp) == 3) {
      ob = present(lower_case(giver),environment(this_object()));
      if (!ob) { return; }
      item_ob = present("ring", this_object());
      if (!item_ob) { return; }
      if (item_ob->short() != "A confirmation ring") {
         tell_object(ob, "The man sighs: 'Thank you but this did not "+
                "make me any happier.'\n");
         tell_object(ob, "The man gives the "+capitalize(item)+
                " back to you.\n");
         move_object(present(item,this_object()), ob);
         return;
      }
      if (ob && item_ob && item_ob->short() == "A confirmation ring" &&
                !ob->query_quests("Return Layla's ring to the old man")) {
         tell_object(ob, "A harmonious, good feeling fills you.\n");
         call_other(ob, "set_quest", "Return Layla's ring to the old man");
      }
      destruct(item_ob);
    }
}
