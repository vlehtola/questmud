inherit "obj/monster";

reset(arg) {
    string chat_str;
    object gloves,trousers,armour,hat,sword;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_race("human");
    set_level(40+random(10));
    set_str(query_str()+50);
    set_max_hp(query_hp()+random(30000));
    set_name("beledor");
    set_alias("man");
    set_short("Beledor Blodimskin, owner of the mansion");
    set_long("Beledor is a normal looking man, his clothes don't\n"+
              "look as valuable as you would think a nobleman's\n"+
              "clothes should. The only thing that draws some attention\n"+
              "on him are his gloves, everything else looks pretty\n"+
              "normal, except that he sobs from time to time.\n");
             
    set_al(40);
    set_aggressive(0);
   
   set_skills("critical",100);
   set_skills("doublehit",100);
   set_skills("dodge",100);
   set_skills("alertness",100);
   set_skills("stun",100);
   set_skills("slash",100);
   
   set_log();

   gloves = clone_object("/wizards/jenny/gnael/rojut/shiny_gloves.c");
    move_object(gloves, this_object());
    init_command("wear gloves");     

   trousers = clone_object("/wizards/jenny/gnael/rojut/trousers.c");
    move_object(trousers, this_object());
    init_command("wear trousers");  

   armour = clone_object("/wizards/jenny/gnael/rojut/leather_armour.c");
    move_object(armour, this_object());
    init_command("wear armour");  

   hat = clone_object("/wizards/jenny/gnael/rojut/hat.c");
    move_object(hat, this_object());
    init_command("wear hat");  

   sword = clone_object("/wizards/jenny/gnael/rojut/short_sword.c");
    move_object(sword, this_object());
    init_command("wield sword");  

                 if (!chat_str) {
                                chat_str = allocate(4);
                                chat_str[0] = "Beledor sobs: 'I have lost all my money!'\n";
                                chat_str[1] = "Beledor sobs 'How can i even pay my guards now!'\n";
                                chat_str[2] = "Beledor sobs: 'I will never gamble again!'\n";
                                chat_str[3] = "Beledor sobs: 'Go away, I don't want to see anyone!'\n";
                         }
                         load_chat(4, chat_str); 
}
