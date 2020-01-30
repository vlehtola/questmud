inherit "obj/monster";

object legu;

reset(arg) {
    string chat_str, a_chat_str;
    ::reset(arg);
    if(arg) { return; }
    legu = clone_object("wizards/devil/area/equ/manlegut");
    move_object( legu ,this_object());
    set_level(100+random(20));
    set_name("Mysterious man");
    set_max_hp(query_max_hp()*18);
    set_skill("deceived attack", 100);
    set_skill("critical", 100);
    set_skill("tumble", 100);
    set_con(query_con()*4);
    set_str(query_str()*4);
    set_alias("man");
    set_short("Mysterious man waiting here for something");
    set_long("This man is just an ordinary gravestone maker, which\n"+
                      "has lost one piece of its most important gravestone.\n" +
                       "Man is wearing old looking clothes, like its life depends\n" +
                        "on that piece of gravestone.\n");
    set_al(100);
    set_gender(1);
    set_race("human");
    init_command("wear all");
    set_log();



    if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] = "Man says 'Darn that Havoc, stole my piece of gravestone'\n";
        chat_str[1] = "Man says 'Can you bring my piece of gravestone back?'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Man says 'You should not attack me!'\n";
    }
    load_chat(20, chat_str);
    load_a_chat(20, a_chat_str);
   
   
}

catch_tell(str) {
   string tmp1,tmp2;
   object ob;
   ::catch_tell(str);
   
   if (sscanf(str, "%s gives %s to you.", tmp1, tmp2) == 2) {
    ob = present("stone", this_object());
    if (ob && this_player()->query_name() == tmp1 && !ob->query_no_save()) {
    destruct(ob);
    write("Man says 'Thank you my fellow, now I can make my gravestone'\n");
    write("Man continues 'Take this amulet for a reward by returning my piece of gravestone'\n");
    move_object(clone_object("/wizards/devil/area/equ/qamu.c"), this_player());
    this_player()->set_quest("Kill the evil emperor");
    say("The man disappears into the shadows.\n");
    call_out("delay_dest",1);
  }
 } 
}

delay_dest() 
{ 
 destruct(legu); 
 destruct(this_object()); 
}

