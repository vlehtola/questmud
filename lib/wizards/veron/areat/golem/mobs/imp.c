inherit "obj/monster";

reset(arg) {
    string chat_str;

    ::reset(arg);
    if(arg) { return; }
    set_level(random(10)+20);
    set_str(query_str()*2);
    set_max_hp(query_hp()+random(500));
    set_al(10);
    set_aggressive(0);
    set_race("imp");
    set_name("imp");
    set_alias("imp");
    set_short("A giggling imp");
    set_long("A small, pudgy imp is giggling insanely. It hops all\n"+
             "around the room in excitement. It is wearing no visible\n"+
		 "equipment.\n");

                        if (!chat_str) {
                                chat_str = allocate(2);
                                chat_str[0] = "The imp chirps in excitement.\n";
                                chat_str[1] = "The imp giggles insanely.\n";
                             

                         }
                         load_chat(2, chat_str); 


             
    
      
   
}