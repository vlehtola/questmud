inherit "obj/monster";

reset(arg) {
    string chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(21);
    set_name("Spectral miner");
    set_short("A spectral miner is moving furiously around the room");
    set_long("This is the tormented spectral apparition of a dead miner. He seems intent on achieving some goal.\n");
    set_exp(58000);
    set_alias("miner","specter","spectre");
    set_al(0);
    set_gender(1);
    set_race("human");
    set_undead(1);



    if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] = "The spectre points at the rubble, makes a hacking movement with his transparent hands.\n";
        chat_str[1] = "The spectral miner holds his hand out expectantly at you.\n";
    }
    
    load_chat(20, chat_str);
   
   
}

catch_tell(str) {
   string tmp1,tmp2;
   object ob;
   ::catch_tell(str);
   
   if (sscanf(str, "%s gives %s to you.", tmp1, tmp2) == 2) {
    ob = present("pick", this_object());
    if (ob && this_player()->query_name() == tmp1 && !ob->query_no_save()) {
    destruct(ob);
    write("The spectre furiously attacks the pile of rubble with the pick you gave him\n");
    write("In a few moments, the rubble is gone, and the southern tunnel is accessible again. \n");
    call_other(environment(this_object()), "add_exit", "south", "/wizards/tiergon/dungeon/a6");
    call_out("delay_dest",1);
    } 
} 
}

delay_dest() 
{ 
 destruct(this_object()); 
}

