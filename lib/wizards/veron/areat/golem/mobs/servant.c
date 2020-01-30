inherit "obj/monster";

reset(arg) {
    string chat_str;
    object armour,dagger;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_level(random(3)+35);
    set_str(query_str()+25);
    set_str(query_dex()*2);
    set_max_hp(query_hp()+random(5000));
    set_name("servant");
    set_alias("human");
  set_race("human");
    set_short("A human servant");
    set_long("A neat-looking middle-aged human servant. He is dressed in a \n"+
             "dress coat. The servant looks busy.\n");
             
    set_al(10);
    set_aggressive(0);
   
   set_skills ("tumble", 10);
   set_skills ("critical", 30);
   set_skills ("doublehit", 30);
    
   armour = clone_object("/wizards/veron/areat/golem/items/coat");
    move_object(armour, this_object());
    init_command("wear coat");      
   dagger = clone_object("/wizards/veron/areat/golem/items/dagger");
    move_object(dagger, this_object());
    init_command("wield dagger");     

                 if (!chat_str) {
                                chat_str = allocate(4);
                                chat_str[0] = "Servant asks: 'What are you doing here?'\n";
                                chat_str[1] = "Servant whistles a happy theme.\n";
                                chat_str[2] = "Servant scratches his head idly.\n";
					  chat_str[3] = "Servant asks: 'How may I serve you?'\n";
                         }
                         load_chat(4, chat_str); 
   
}
