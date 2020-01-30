inherit "obj/monster";

reset(arg) {
    string chat_str;
    object armour,trousers,sword;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_race("giant");
    set_level(random(15)+15);
    set_name("geremod");
    set_alias("guard");
    set_short("Geremod the brave is guarding the basements");
    set_long("Geremod is a middle-aged giant who has a very\n"+ 
              "good reputation in the city of Gnael. He is known\n"+
              "as 'the brave' because he once saved a girl who\n"+
              "was captured by a few bandits. Now that he is\n"+
              "middle-aged he started to work as a guard in this\n"+
              "mansion. He enjoys using his muscles like every giant\n"+
              "so guarding is an obvious job for him.\n");

    set_block_dir("down");
    set_al(-3);
    set_aggressive(0);
    set_log();
   
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
                                chat_str[0] = "Geremod grumbles: 'You don't belong here'\n";
                                chat_str[1] = "Geremod grumbles: 'Please go back'\n";
                         }
                         load_chat(4, chat_str); 
}
