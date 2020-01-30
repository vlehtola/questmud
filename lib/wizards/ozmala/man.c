inherit "obj/monster";
status q;
reset(arg) {
        string chat_str;
        ::reset(arg);
        if(arg) {return; }
        q = 0;
        set_name("man");
        set_level(20);
        set_gender(1);
        set_race("human");
        set_special(50);
        set_al(-5);
        set_short("A man cleaning fishing equipment");
        set_long("Man is wearing knitted fabric which has a small anchor in it.\n"+
                 "He has a pipe in his mouth and he is cleaning and repairing fishing\n"+
                 "equipment.\n");
 if(!q) {
        chat_str = allocate(2);
        chat_str[0] = "Man says: 'Welcome to my humble house.'\n";
        chat_str[1] = "Man says: 'I have lost my watch, can you bring it back?'\n";
load_chat(3, chat_str);
}
}
void special_move() {
init_command("close door");
}

catch_tell(str) {
        string tmp1, tmp2, chat_str;
           object ob;
        ::catch_tell(str);
   if (sscanf(str, "%s gives %s to you.", tmp1, tmp2) == 2) {
    ob = present("kulta_kello", this_object());
    if (ob && this_player()->query_name() == tmp1) {
    destruct(ob);
    write("Man says: 'Thank you.\n");
  q = 1;
chat_str = allocate(1);
chat_str[0] = "Man says: 'Now i can finally see the right time.'\n";
load_chat(3, chat_str);
    this_player()->set_quest("Bring man's watch back");

  }
 }
}
