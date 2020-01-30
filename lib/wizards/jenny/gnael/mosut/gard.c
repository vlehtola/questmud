inherit "obj/monster";

reset(arg) {
    string chat_str;
    object shirt,trousers,sword;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_race("human");
    set_level(random(10)+25);
    set_name("gard");
    set_alias("man");
    set_short("Gard Lindbur, the father of Leila");
    set_long("Gard is nearly 70 years old man and he is one of\n"+ 
              "the most respected nobles in the city of Gnael.\n"+
              "He owns some of the stores in Gnael and he is\n"+  
              "very proud of his daughter Leila.\n");
             
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
                                chat_str[0] = "Gard says: 'The air is so clean here, lets come here again tomorrow'\n"; 
                                chat_str[1] = "Gard says: 'Of course you don't have to marry Bolodir if you don't want!'\n";
                         }
                         load_chat(4, chat_str); 
}
