inherit "obj/monster";

reset(arg) {
    object money;
    string chat_str, a_chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(40);
    set_max_hp(query_max_hp()*2);
    set_name("keeper");
    set_alias("human");
    set_race("human");
    set_short("A storage keeper");
    set_long("A storage kepeer is here to keep storage full and clean.\n");
    set_al(10);
    set_gender(2);
    set_skill("alertness", 100);
    set_skill("foresee attack", 100);
    set_skill("counter spell", 100);
    set_log();


     if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] =
        "keeper mumbles: 'I need more flour.'\n";
        chat_str[1] =
        "Keeper says: 'Go get me more flour please.'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Keeper says: 'i love this job.'\n";
    }
    load_chat(3, chat_str);
    load_a_chat(3, a_chat_str);


}

catch_tell(str) {
   string tmp1,tmp2;
   object ob;
   ::catch_tell(str);

   if (sscanf(str, "%s gives %s to you.", tmp1, tmp2) == 2) {
    ob = present("sack", this_object());
    if (ob && this_player()->query_name() == tmp1 && !ob->query_no_save()) {
    destruct(ob);
    write("Keeper says: 'Thank you very much, now we can make more bread.\n");
    this_player()->set_quest("Help the baker");
  }
 }
}
