inherit "obj/monster";

reset(arg) {
    string chat_str;
    object belt;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_level(45);
    set_exp(4024532);
    set_str(query_str()+50);
    set_dex(query_dex()+500);
    set_max_hp(query_hp()+random(800));
    set_name("thief");
    set_alias("man");
    set_race("human");
    set_short("Thief lurking in the shadows");
    set_long("This man is wearing very valuable looking jeweled belt\n"+
              "and there seems to be small diamonds embedded into the\n"+
              "center of the belt. When you look into this mans eyes, \n"+
              "you see that he fears absolutely nothing\n");
             
    set_al(-50);
    set_aggressive(0);
   
   set_skills("critical",100);
   set_skills("doublehit",100);
   set_skills("dodge",100);
   set_skills("alertness",100);
   set_skills("stun",100);
   set_skills("slash",100);

   belt = clone_object("/wizards/jenny/linnake/rojut/thief_belt.c");
    move_object(belt, this_object());
    init_command("wear belt");     

                 if (!chat_str) {
                                chat_str = allocate(4);
                                chat_str[0] = "Thief whispers: 'Don't even think about attacking me!'\n";
                                chat_str[1] = "Thief whispers: 'I stole this belt from the king!'\n";
                                chat_str[2] = "Thief whispers: 'My mage friend will exchange this to cash!'\n";
                                chat_str[3] = "Thief says:'I will get atleast 2000 when mage transforms this'\n";
                         }
                         load_chat(4, chat_str); 
}
