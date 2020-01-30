inherit "obj/monster";

reset(arg) {
    string chat_str;
    object shirt,trousers,sword;
    ::reset(arg);
    if(arg) { return; }
    set_gender(2);
    set_race("human");
    set_level(random(25)+10);
    set_name("bertha");
    set_alias("wife");
    set_short("Bertha Higledilodrim, the mayor's wife");
    set_long("Bertha is nearly sixty years old woman who has been\n"+ 
              "married to her husband Harald for over fourty long years. \n"+
              "She is one of the most respected womans in the city and\n"+
              "she looks very elegant. Her hair is getting gray, but you\n"+
              "still see some glorious looking red hair on some parts\n");
             
    set_al(10);
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
                                chat_str[0] = "Bertha says: 'If someone only could kill Mondasa..'\n";
                                chat_str[1] = "Bertha says: 'My husband has the key..'\n";
                         }
                         load_chat(4, chat_str); 
}
