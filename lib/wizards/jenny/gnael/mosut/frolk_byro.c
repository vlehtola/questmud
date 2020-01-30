inherit "obj/monster";

reset(arg) {
    string chat_str;
    object armour,trousers,sword;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_race("hobbit");
    set_level(random(15)+28);
    set_name("frolk");
    set_alias("bureaucrat");
    set_short("Frolk Frousendibler, busy looking bureaucrat");
    set_long("Frolk Frousendibler, very busy looking bureaucrat,\n"+ 
              "he is doing some paper work and mumbling something\n"+
              "while running from place to place. He is wearing\n"+
              "a leather armour and a leather trousers, he is also\n"+
              "wielding a short sword, but he doesn't look very strong\n");
             
    set_al(20);
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
                                chat_str[0] = "Frolk mumbles: 'They say that there are some evil powers in the well'\n";
                                chat_str[1] = "Frolk mumbles: 'Our town seems peaceful, but evil half-god Momdasa...'\n";
                         }
                         load_chat(4, chat_str); 
}
