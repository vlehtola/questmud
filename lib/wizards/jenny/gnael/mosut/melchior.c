inherit "obj/monster";

reset(arg) {
    string chat_str;
    object armour,trousers,sword;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_race("human");
    set_level(random(5)+10);
    set_name("melchior");
    set_alias("guard");
    set_short("Melchior Morostoover is guarding the entrance");
    set_long("Melchior is a 16 years old boy who just started his work\n"+ 
              "as a guard to get his mother some money. He has a dirty\n"+
              "looking short brown hair and his face is full of pimples.\n"+
              "He doesn't look very strong, but he sure look dumb. He is\n"+
              "wearing a leather armour and leather trousers. He is also\n"+
              "wielding a short sword which seems to be the standard weapon in\n"+
              "Gnael.\n");

    set_block_dir("enter");
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
                                chat_str[0] = "Melchior says: 'I won't let you pass'\n";
                                chat_str[1] = "Melchior says: 'Please go away, I don't want to fight'\n";
                         }
                         load_chat(4, chat_str); 
}
