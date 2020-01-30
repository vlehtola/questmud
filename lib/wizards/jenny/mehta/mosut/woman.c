inherit "obj/monster";

reset(arg) {
    object money;
    object armour;
    string chat_str, a_chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(40);
    set_max_hp(query_max_hp()*2);
    set_name("woman");
    set_alias("woman");
    set_race("human");
    set_short("A strange looking woman is boiling something");
    set_long("A strange looking woman is boiling something odd in her\n"+
             "pot. She is wearing dirty red robe and a pair of disgusting\n"+
             "leggings. When you look closely, you notice that she is\n"+
             "not very old, but she already has some wrinkles.\n");
    set_al(10);
    set_gender(2);
    set_skill("kick", 100);
    set_skill_chance("kick", 100);
    set_skill("bare hands", 100);
    set_skill("attack", 100);
    set_skill("throw weight", 60);
    set_skill("enhance criticals", 50);
    set_skill("inner strength", 100);
    set_skill("dodge", 100);
    set_skill("alertness", 100);
    set_skill("foresee attack", 100);
    set_log();

        armour = clone_object("/wizards/jenny/mehta/rojut/legurit.c");
        move_object(armour, this_object());
        init_command("wear leggings");


    if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] =
"Woman mumbles: 'Ubba jobba gobba GUUM!'\n";
        chat_str[1] =
"Woman yells: 'Go get me an apple right away!'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "woman screams: 'Damn that troll, it is always bugging me!'\n";
    }
    load_chat(3, chat_str);
    load_a_chat(3, a_chat_str);
   
   
}

catch_tell(str) {
   string tmp1,tmp2;
   object ob;
   ::catch_tell(str);
   
   if (sscanf(str, "%s gives %s to you.", tmp1, tmp2) == 2) {
    ob = present("apple", this_object());
    if (ob && this_player()->query_name() == tmp1 && !ob->query_no_save()) {
    destruct(ob);
    write("Woman says: 'Thank you very much, now i can do this potion!\n");
    this_player()->set_quest("Help the woman in Toranth forest");
  }
 } 
}
