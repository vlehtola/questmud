inherit "obj/monster";

reset(arg) {
    string chat_str;
    object armour,trousers,sword;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_race("giant");
    set_level(random(8)+28);
    set_name("uglah");
    set_alias("gatekeeper");
    set_short("Uglah Guglah, weird looking giant gatekeeper");
    set_long("Uglah Guglah comes from an ancient shrine where giants\n"+ 
              "usually live. A few hundred years ago he was banished from\n"+
              "the shrine because he was too kind, that is why he nowadays\n"+
              "works as a gatekeeper in the city of Gnael. He is wearing\n"+
              "a leather armour and leather trousers. He is also wielding\n"+
              "a typical short sword. From time to time he stomps the ground\n"+
              "with his huge feet.\n");
             
    set_al(5);
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
                                chat_str[0] = "Uglah thunders: 'Nice weather today!'\n";
                                chat_str[1] = "Uglah stomps the ground hard\n";
                         }
                         load_chat(4, chat_str); 
}
