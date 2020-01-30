inherit "obj/monster";

reset(arg) {
    string chat_str;
    object armour,trousers,sword;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_race("orc");
    set_level(random(8)+28);
    set_name("meglah");
    set_alias("gatekeeper");
    set_short("Meglah Glezxagh, an angry looking orc gatekeeper");
    set_long("Meglah Glezxagh is a very famous for his actions in\n"+ 
              "battles, but nowadays he is working for the city of Gnael\n"+
              "as a gatekeeper. He is wearing a leather armour and\n"+
              "leather trousers which seem to look very good on his\n"+
              "green skin. On his right hand he is wielding a typical\n"+
              "short sword. He is not hostile, but he does have very\n"+
              "angry look on his face.\n");
             
    set_al(0);
    set_aggressive(0);
   
   armour = clone_object("/wizards/jenny/gnael/rojut/leather_armour");
    move_object(armour, this_object());
    init_command("wear armour");      
   
   trousers = clone_object("/wizards/jenny/gnael/rojut/trousers");
    move_object(trousers, this_object());
    init_command("wear trousers");      

   sword = clone_object("/wizards/jenny/gnael/rojut/short_sword");
    move_object(sword, this_object());
    init_command("wield sword");     
 
                 if (!chat_str) {
                                chat_str = allocate(2);
                                chat_str[0] = "Meglah says: 'Get in get in I don't have all day!'\n";
                                chat_str[1] = "Meglah gives an angry look at you\n";
                         }
                         load_chat(4, chat_str); 
}
