inherit "obj/monster";

reset(arg) {
    string chat_str;
    object shirt,trousers;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_race("human");
    set_level(random(10)+65);
    set_name("glenfast");
    set_alias("man");
    set_short("A wicked looking man named 'Glenfast'");
    set_long("Glenfast is a famous assassin and a highly respected\n"+ 
              "man. It is said that this man can stab anyone\n"+
              "in a blink of an eye. His eyes are glowing red\n"+ 
              "and he is very muscular. He is wearing an old shirt\n"+
              "and old trousers.\n");
             
    set_al(5);
    set_aggressive(0);
   
   shirt = clone_object("/wizards/jenny/gnael/rojut/shirt");
    move_object(shirt, this_object());
    init_command("wear shirt");      
   
   trousers = clone_object("/wizards/jenny/gnael/rojut/worn_trousers");
    move_object(trousers, this_object());
    init_command("wear trousers");         
 
                 if (!chat_str) {
                                chat_str = allocate(2);
                                chat_str[0] = "Glenfast whispers: 'If you want to be assasin, you must knock door three times'\n"; 
                                chat_str[1] = "Glenfast whispers: 'Assassins are not going to recruit anyone untill Mondasa is dead'\n";
                         }
                         load_chat(4, chat_str); 
}
