inherit "obj/monster";

reset(arg) {
    string chat_str;
    object armour,trousers,sword;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_race("human");
    set_level(random(8)+28);
    set_name("lendor");
    set_alias("gatekeeper");
    set_short("Lendor Boflar, a kind looking gatekeeper");
    set_long("Lendor Boflar is a very kind looking man, but pretty\n"+ 
              "strong also. It seems like he would never hurt a fly\n"+
              "unless he would have to, He is wearing a gatekeeper's normal\n"+
              "outfit which includes a leather armour, leather trousers\n"+
              "and a small short sword. He is humming some familiar\n"+
              "theme, but you just can't remember where you have heard\n"+
              "it before.\n");
             
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
                                chat_str[0] = "Lendor says: 'Hello there stranger, please enjoy our city'\n";
                                chat_str[1] = "Lendor starts humming some familiar theme\n";
                         }
                         load_chat(4, chat_str); 
}
