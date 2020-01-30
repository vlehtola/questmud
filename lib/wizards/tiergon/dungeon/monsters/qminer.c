inherit "obj/monster";

reset(arg) {
    string chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(8);
    set_exp(1);
    set_name("Miner");
    set_alias("miner");
    set_gender(1);
    set_race("human");
    set_short("A grievously wounded miner");
    set_long("This man seems to have been poisoned by some fell creature"+
             "before he was trapped behind the collapsed section of the"+
             "tunnel\n"); 
    set_al(15);
    set_log();


    if (!chat_str) {
        chat_str = allocate(1);
        chat_str[0] = "The miner convulses from the effects of some horrible poison!\n";
    }
    load_chat(20, chat_str);
}

catch_tell(str) {
   string tmp1,tmp2;
   object ob;
   ::catch_tell(str);
   
   if (sscanf(str, "%s gives %s to you.", tmp1, tmp2) == 2) {
    ob = present("herbs", this_object());
    if (ob && this_player()->query_name() == tmp1 && !ob->query_no_save()) {
    destruct(ob);
    write("The miner hungrily consumes the herbs, and seems instantly better\n");
    write("The miner says 'Please accept this pendant as a token of my gratitude. May it serve you better against these fiends!'\n");
    move_object(clone_object("/wizards/tiergon/eq/pendant"), this_player());
    write("Congratulations, you have completed the Poisoned Miner quest!\n"); 
    this_player()->set_quest("Poisoned Miner", 15);
    say("The miner swears to never return to the mines, and runs out.\n");
    call_out("delay_dest",1);
  }
 } 
}

delay_dest() 
{ 
 destruct(this_object()); 
}

