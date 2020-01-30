inherit "obj/monster";

reset(arg) {
    object armour;
    string chat_str, a_chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(15);
    set_name("woman");
    set_alias("woman");
    set_race("human");
    set_short("A sad looking woman is standing by the fire");
    set_long("When you at look her you instantly notice that she\n"+
             "is very hungry. She looks almost like a ghost\n"+
             "because she is so thin. The only thing she is wearing\n"+
             "is a leather armour, but it doesn't cover much\n"+
             "of her body\n");
    set_al(10);
    set_gender(2);

        armour = clone_object("/wizards/jenny/gnael/rojut/leather_armour.c");
        move_object(armour, this_object());
        init_command("wear armour");


    if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] =
"Woman sobs: 'Im so hungry...'\n";
        chat_str[1] =
"Woman sobs: 'I heard there is very good meat in the mansion...'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Woman sobs: 'why, oh why!'\n";
    }
    load_chat(3, chat_str);
    load_a_chat(3, a_chat_str);
   
   
}

catch_tell(str) {
   string tmp1,tmp2;
   object ob;
   ::catch_tell(str);
   
   if (sscanf(str, "%s gives %s to you.", tmp1, tmp2) == 2) {
    ob = present("meat", this_object());
    if (ob && this_player()->query_name() == tmp1 && !ob->query_no_save()) {
    destruct(ob);
    write("Woman says: 'Oh! thank you very much for giving me food\n");
    this_player()->set_quest("Feed the woman in Gnael");
  }
 } 
}
