inherit "obj/monster";

reset(arg) {
    string chat_str;
    object shirt,trousers,sword;
    ::reset(arg);
    if(arg) { return; }
    set_gender(2);
    set_race("human");
    set_level(random(10)+18);
    set_name("leila");
    set_alias("woman");
    set_short("Leila Lindbur, one of the Gnael's nobles");
    set_long("Leila is about 25 years old woman and she is\n"+ 
              "the daughter of a mighty nobleman Gard Lindbur. She is\n"+
              "wearing very comfortable looking trousers and\n"+  
              "a silk shirt. You also notice that she has a short\n"+
              "sword tied on her wrist.\n");
             
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
                                chat_str[0] = "Leila says: 'Oh father, I so enjoy walking on the streets'\n"; 
                                chat_str[1] = "Leila says: 'Father...Do I really have to marry that Bolodir?'\n";
                         }
                         load_chat(4, chat_str); 
}
