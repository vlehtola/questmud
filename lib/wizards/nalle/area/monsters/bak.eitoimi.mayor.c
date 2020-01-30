inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(21);
    set_gender(1);
    set_race("human");
    set_name("The Mayor");
    set_alias("mayor");
    set_short("The mayor of Chamron");
    set_long("The mayor is a man in his fifties, but still a strong man. He seems puzzled.\n");
    set_al(10);
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] ="The Mayor mutters: 'Damned Darvox, what will we do with him.'\n";
        chat_str[1] ="The Mayor says: 'I didn't remember I had a meeting today.'\n";
        chat_str[2] ="The Mayor grunts: 'I just need his silvery staff as proof of his death.'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "The Mayor growls: 'Just like I didn't have enough problems already.'\n";
    }
    load_chat(20, chat_str);
    load_a_chat(20, a_chat_str);

}

catch_tell(str) {
    string giver,item, tmp;
    object ob;
    if (!str) { return 1; }
    if (sscanf(str, "%s gives %s to %s.", giver, item, tmp) == 3) {
      ob = present(lower_case(giver),environment(this_object()));
      if (!ob) { return; }
      if (!present("taikasauvake", (this_object()))) {
	 tell_object(ob, "The mayor says: 'Sorry, but this is not "+
		"Darvox's staff.'\n");
	 tell_object(ob, "The mayor hands the "+capitalize(item)+
		" back to you.\n");
	 move_object(present(item,this_object()), ob);
	 return;
      }
      if(present("silvery staff", this_object())->query_no_save()) {
        tell_object(ob, "Mayor says: 'This is not right.'\n");
        destruct(present("silvery staff"));
      }
      if (ob && !ob->query_quest("Slay Darvox")) {
         tell_object(ob, "You have completed the quest \"Slay Darvox\".\n");
         ob->set_quest("Slay Darvox");
      }
      destruct(present(item,this_object()));
    }
}