inherit "obj/monster";

reset(arg) {
    string chat_str;
    object armour,trousers,sword;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_race("giant");
    set_level(random(20)+30);
    set_name("fjoldor");
    set_alias("guard");
    set_short("Fjoldor the giant is guarding the staircase");
    set_long("Fjoldor is a massive giant who takes his work very seriously.\n"+ 
              "His fists are huge and his passion is to be guard. His long blond\n"+
              "hair looks gorgeous and his yellow eyes glow with mysterious\n"+
              "glow. He is wearing a leather armour and leather trousers,\n"+
              "he is also wielding a short sword which seems to be a standard\n"+
              "weapon in Gnael.\n");

    set_block_dir("up");
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
                                chat_str[0] = "Fjoldor grumbles: 'You are not allowed to enter'\n";
                                chat_str[1] = "Fjoldor grumbles: 'Go away please'\n";
                         }
                         load_chat(4, chat_str); 
}
