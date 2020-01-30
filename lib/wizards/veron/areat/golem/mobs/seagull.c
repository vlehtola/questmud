inherit "obj/monster";

reset(arg) {
    string chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(10);
    set_al(10);
    set_aggressive(0);
    
    set_name("seagull");
    set_alias("bird");
    set_animal(1);
    set_short("A curious-looking seagull");
    set_long("A large seagull pecking seeds from the bucket. It eyes you\n"+
             "curiously. Its bill looks uncomfortably sharp.\n");

                         if (!chat_str) {
                                chat_str = allocate(2);
                                chat_str[0] = "The seagull pecks some seeds from the bucket.\n";
                                chat_str[1] = "The seagull squalls.\n";
                              
                         }
                         load_chat(2, chat_str); 

	
             
    
      
   
}