inherit "obj/monster";

reset(arg) {
    string chat_str;
    object shirt,trousers,hat;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_race("human");
    set_level(random(4)+10);
    set_name("helga");
    set_alias("maid");
    set_short("Helga is here cleaning the mansion");
    set_long("Helga is the maid of the mansion. She keeps the place\n"+ 
              "clean and gives a good whooping if someone steps in\n"+
              "with muddy boots or a dirty cloak. She has brown eyes and\n"+
              "she is wearing a typical shirt used by the people of Gnael.\n");
             
    set_al(3);
    set_aggressive(0);
   
   shirt = clone_object("/wizards/jenny/gnael/rojut/shirt");
    move_object(shirt, this_object());
    init_command("wear shirt");      
   
   trousers = clone_object("/wizards/jenny/gnael/rojut/trousers");
    move_object(trousers, this_object());
    init_command("wear trousers");      

   hat = clone_object("/wizards/jenny/gnael/rojut/hat");
    move_object(hat, this_object());
    init_command("wear hat");     
 
                 if (!chat_str) {
                                chat_str = allocate(2);
                                chat_str[0] = "Helga says: 'Don't bring dirt into the mansion'\n";
                                chat_str[1] = "Helga says: 'This job is perfect, I enjoy cleaning'\n";
                         }
                         load_chat(4, chat_str); 
}
