inherit "obj/monster";

reset(arg) {
    string chat_str;
    object armour,trousers,sword;
    ::reset(arg);
    if(arg) { return; }
    set_gender(2);
    set_race("human");
    set_level(random(8)+28);
    set_name("nadia");
    set_alias("gatekeeper");
    set_short("Nadia Preditonth, a cute looking female gatekeeper ");
    set_long("Nadia Preditonth is a very cute looking female gatekeeper, she\n"+ 
              "has a long red hair and blue eyes. She became a gatekeeper\n"+
              "because her father was a famous gatekeeper for a long time,\n"+
              "but he was killed a short while ago. Only way to keep the\n"+
              "family alive was to get job and the only job available was this.\n"+
              "She is not very strong looking, but she does look pretty smart.\n");
             
    set_al(9);
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
                                chat_str[0] = "Nadia says: 'Damn I hate this outfit'\n";
                                chat_str[1] = "Nadia blinks cutely\n";
                         }
                         load_chat(4, chat_str); 
}
