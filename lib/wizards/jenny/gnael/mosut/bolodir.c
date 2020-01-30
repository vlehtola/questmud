inherit "obj/monster";

reset(arg) {
    string chat_str;
    object shirt,trousers,sword;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_race("human");
    set_level(random(13)+30);
    set_name("bolodir");
    set_alias("man");
    set_short("Bolodir Gardanus is looking for Leila");
    set_long("Bolodir is a young man and he is one of Gnael's\n"+ 
              "nobles. He seems to be looking for someone and\n"+
              "he seems a bit worried. He is wearing normal\n"+  
              "clothes of a noble which includes a silk shirt\n"+
              "and trousers, he is also carrying a short sword.\n");
             
    set_al(5);
    set_aggressive(0);
   
   shirt = clone_object("/wizards/jenny/gnael/rojut/silk_shirt");
    move_object(shirt, this_object());
    init_command("wear shirt");      
   
   trousers = clone_object("/wizards/jenny/gnael/rojut/clean_trousers");
    move_object(trousers, this_object());
    init_command("wear trousers");         

   sword = clone_object("/wizards/jenny/gnael/rojut/short_sword");
    move_object(sword, this_object());
    init_command("wield sword");         
 
                 if (!chat_str) {
                                chat_str = allocate(2);
                                chat_str[0] = "Bolodir says: 'Oh where are you Leila!'\n"; 
                                chat_str[1] = "Bolodir says: 'Leila don't leave me! I love you!'\n";
                         }
                         load_chat(4, chat_str); 
}
