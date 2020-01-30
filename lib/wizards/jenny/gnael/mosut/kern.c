inherit "obj/monster";

reset(arg) {
    string chat_str;
    object armour,trousers,sword;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_race("human");
    set_level(random(8)+28);
    set_name("kern");
    set_alias("gatekeeper");
    set_short("Kern Harblem, a sturdy looking gatekeeper");
    set_long("Kern Harblem is a very strong-looking man with a fearsome look\n"+ 
              "in his deep red eyes. Moist wind makes a caressing play\n"+
              "with his long blonde hair and he looks very calm. He is\n"+
              "wearing a typical working outfit which includes a leather\n"+
              "armour and leather trousers, he is also wielding a small,\n"+
              "but very sharp-looking short sword. He is walking around\n"+
              "and he does his best to look important.\n");
             
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
                                chat_str[0] = "Kern says: 'Soon my shift is over'\n";
                                chat_str[1] = "Kern walks around looking important\n";
                         }
                         load_chat(4, chat_str); 
}
