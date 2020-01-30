inherit "obj/monster";

reset(arg) {
    string chat_str;
    object armour,trousers,sword;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_race("giant");
    set_level(random(11)+35);
    set_name("garf");
    set_alias("guard");
    set_short("Garf Sfatger, a peaceful looking giant");
    set_long("A huge creature called 'Garf Sfatger' and his brother\n"+ 
              "Larf Sfatger were hired to guard this enormous mansion\n"+
              "from acts of crime. Garf is the happy one of these brothers\n"+
              "and he is smiling to everyone who passes by. He is wearing\n"+
              "a leather armour and leather trousers, he is also wielding\n"+
              "a short sword which seems to be a standard weapon in Gnael.\n");

    set_block_dir("mansion");
    set_al(3);
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
                                chat_str[0] = "Garf grumbles: 'Nice to meet you'\n";
                                chat_str[1] = "Garf grumbles: 'Don't try to enter this mansion please'\n";
                         }
                         load_chat(4, chat_str); 
}
