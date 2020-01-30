inherit "obj/monster";

reset(arg) {
    object cloak,sword;
    string chat_str, a_chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(68);
    set_name("feleodor");
    set_alias("captain");
    set_race("human");
    set_short("Feleodor Brogotuknik, the captain of guards");
    set_long("Feleodor is a very handsome looking young man.\n"+
             "When you look him into eyes, you see warm\n"+
             "eyes looking back. Feleodor is a great fighter,\n"+
             "but without a reason, he would not harm a fly.\n"+
             "He is wearing a beautiful long black cape and\n"+
             "in his right hand he is wielding a golden sword.\n");
    set_al(10);
    set_gender(1);
    set_log();

        cloak = clone_object("/wizards/jenny/gnael/rojut/law_cloak.c");
        move_object(cloak, this_object());
        init_command("wear cloak");

        sword = clone_object("/wizards/jenny/gnael/rojut/golden_sword.c");
        move_object(sword, this_object());
        init_command("wield sword");

    if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] =
"Feleodor says: 'I am powerful, but even i can't win Mondasa'\n";
        chat_str[1] =
"Feleodor says: 'I want Mondasa's head'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Feleodor says: 'Don't you break the law kid!'\n";
    }
    load_chat(3, chat_str);
    load_a_chat(3, a_chat_str);
   
   
}

catch_tell(str) {
   string tmp1,tmp2;
   object ob;
   ::catch_tell(str);
   
   if (sscanf(str, "%s gives %s to you.", tmp1, tmp2) == 2) {
    ob = present("head", this_object());
    if (ob && this_player()->query_name() == tmp1 && !ob->query_no_save()) {
    destruct(ob);
    write("Feleodor says: 'You did it! You saved our town! I'll go bury this head somewhere far!\n");
    this_player()->set_quest("Save the city of Gnael");
    call_out( "delay_dest" , 0 , this_object() );
  }
 } 
}

int delay_dest(object obj)
{
destruct(obj);
return 1;
}
