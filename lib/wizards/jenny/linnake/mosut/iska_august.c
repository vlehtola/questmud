inherit "obj/monster";
int tehty;
int i = 1;

reset(arg) {
    string chat_str, a_chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(20);
    set_name("august");
    set_alias("human");
    set_short("August III, the former king of this castle");
    set_long("Former king of this castle and father of king August IV.\n"+
             "He is very old and he coughes all the time. He is wearing\n"+
             "only a dark robe which covers his body completely. He looks\n"+
             "like his starving, but fortunately he does have some bread\n"+
             "on his hands.\n");
    set_al(500);
    set_gender(1);
    set_race("human");

    if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] =
"August says: 'Please, get me my sceptre so I can rule again.'\n";
        chat_str[1] =
"August says: 'My son stole my kingdom! I need my sceptre!'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "August says: 'I know my son hid my sceptre somewhere!'\n";
    }
    load_chat(3, chat_str);
    load_a_chat(3, a_chat_str);
   
   
}

catch_tell(str) {
   string tmp1,tmp2;
   object ob;
   ::catch_tell(str);
   
   if (sscanf(str, "%s gives %s to you.", tmp1, tmp2) == 2) {
    ob = present("sceptre", this_object());
     if (!tehty && ob && this_player()->query_name() == tmp1 && !ob->query_no_save()) {
    destruct(ob);
    write("August says: 'Thank you! As a result of your trouble, I'll give you\n");
    write("this ring as a reward.\n");
    write("August continues: 'It's the ring of a great warrior Ul'grath.\n");
    write("Use this ring wisely and remember it is very powerful!'\n");
    move_object(clone_object("/wizards/jenny/linnake/rojut/qring.c"), this_player());
    this_player()->set_quest("Save the kingdom of Roxen");

call_out("palautettu",1);
tehty = 1;
  }
 } 
}
palautettu(i) {
string chat_str;
if(!chat_str) {
   chat_str = allocate(1);
   chat_str[0] = "August says: 'I got my sceptre back so I can rule again.'\n";
 }
load_chat(3,chat_str);

}
