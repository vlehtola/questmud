inherit "obj/monster";

reset(arg) {
    string chat_str;
    object armour,trousers,sword;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_race("giant");
    set_level(random(11)+45);
    set_name("larf");
    set_alias("guard");
    set_short("Larf Sfatger, an angry looking giant");
    set_long("A huge creature called 'Larf Sfatger' and his brother\n"+ 
              "Garf Sfatger were hired to guard this enormous mansion\n"+
              "from acts of crime. Larf is the mean and angry one of these\n"+
              "brothers and he is yelling to everyone who passes by. He is\n"+
              "wearing a leather armour and leather trousers, he is also\n"+
              "wielding a short sword which seems to be a standard weapon in\n"+
              "Gnael.\n");

    set_block_dir("mansion");
    set_al(-3);
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
                                chat_str[0] = "Larf grumbles: 'Go away you punk!'\n";
                                chat_str[1] = "Larf grumbles: 'Don't come any closer or i'll kill ya!'\n";
                         }
                         load_chat(4, chat_str); 
}
