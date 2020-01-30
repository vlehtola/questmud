inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(90);
    set_name("caveman");
    set_alias("man");
    set_short("A hunchbacked Caveman");
    set_long("The caveman is old and hunchbacked, covered with dirt and dust.\n"+
             "He is thin, almost at the point of exhaustion. His bones are shining\n"+
             "through his skin, in legs, in hands, in face and in his whole body.\n"+
             "His dirty, hair is long and messy, covering up his small eyes. He\n"+
             "has been living in the cave up child till now.\n");
    set_al(10);
    set_gender(1);
    set_race("human");



    if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] =
"Caveman says: 'Please, bring me some food.'\n";
        chat_str[1] =
"Caveman says: 'The Enchantress is hiding somewhere in the northern forest.'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Caveman says: 'Cooked raven is my favourite food!'\n";
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
    write("Caveman says: 'Thank you! As a result of your trouble, I'll give you\n");
    write("this head for a reward.\n");
    write("Caveman continues: 'It's the head of Enchantress husband. Use it to\n");
    write("lure the Enchantress out of her hiding place.'\n");
    move_object(clone_object("/wizards/irmeli/valley/object/head.c"), this_player());
    this_player()->set_quest("Help the Caveman");
  }
 } 
}
