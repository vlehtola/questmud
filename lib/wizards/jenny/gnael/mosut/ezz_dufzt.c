inherit "obj/monster";

reset(arg) {
    string chat_str;
    object armour,trousers,sword;
    ::reset(arg);
    if(arg) { return; }
    set_gender(3);
    set_race("lizardman");
    set_level(random(8)+28);
    set_name("ezz'dufzt");
    set_alias("gatekeeper");
    set_short("Ezz'Dufzt, fearsome lizardman gatekeeper");
    set_long("A very tall lizardman gatekeeper, it looks pretty\n"+ 
              "strong and it is wearing a leather armour and very\n"+
              "comfortable looking trousers. It swings a short\n"+
              "sword from time to time and there is a mean smile\n"+
              "on it's face.\n");
             
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
                                chat_str[0] = "Ezz'Dufzt hisses: 'shhhtop running pleashhhh'\n";
                                chat_str[1] = "Ezz'Dufzt swings a short sword above it's head\n";
                         }
                         load_chat(4, chat_str); 
}
