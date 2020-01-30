inherit "obj/monster";

reset(arg) {
    string chat_str;
    object shirt,trousers;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_race("catfolk");
    set_level(random(30)+1);
    set_name("lady");
    set_alias("woman");
    set_short("A happy looking catfolk lady");
    set_long("A happy looking catfolk lady is here doing her daily\n"+ 
              "routines. She is making food for her children and\n"+
              "washing some dishes with her tail at the same time.\n"+ 
              "She is wearing a shirt and leather trousers.\n");
             
    set_al(5);
    set_aggressive(0);
   
   shirt = clone_object("/wizards/jenny/gnael/rojut/shirt");
    move_object(shirt, this_object());
    init_command("wear shirt");      
   
   trousers = clone_object("/wizards/jenny/gnael/rojut/trousers");
    move_object(trousers, this_object());
    init_command("wear trousers");         
 
                 if (!chat_str) {
                                chat_str = allocate(2);
                                chat_str[0] = "Lady meows: 'It is rumoured that there is a thief guild in Gnael'\n";
                                chat_str[1] = "Lady meows: 'I heard that the mayor has the key to the locked door in the well'\n";
                         }
                         load_chat(4, chat_str); 
}
