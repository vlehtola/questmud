inherit "obj/monster";

reset(arg) {
    string chat_str;
    object armour,trousers,sword;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_race("human");
    set_level(random(8)+28);
    set_name("bernard");
    set_alias("gatekeeper");
    set_short("Bernard Bloxendofler, a handsome looking gatekeeper");
    set_long("A young man with short brown hair and a small moustache.\n"+ 
              "His blue eyes look happy and he is whistling some\n"+
              "familiar melodies. He is wearing a normal leather\n"+
              "armour and neat looking leather trousers.\n");
             
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
                                chat_str[0] = "Bernard says: 'Welcome to Gnael'\n";
                                chat_str[1] = "Bernard scratches his head\n";
                         }
                         load_chat(4, chat_str); 
}
