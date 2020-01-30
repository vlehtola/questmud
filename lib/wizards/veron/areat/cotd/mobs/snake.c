inherit "obj/monster";

reset(arg) {
    string chat_str;
   
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_level(random(10)+15);
    set_str(query_str()+30);
    set_str(query_con()+30);
    set_name("rattlesnake");
    set_alias("snake");
    set_short("A rattlesnake");
    set_long("A quite large rattlesnake  \n"+
             "A dusty-looking rather large rattlesnake lies hissing in\n"+
 	     "the ground. It's tail makes a rattling sound.\n");
           
             
    set_al(0);
    set_aggressive(0);
    set_animal(1);
  

                 if (!chat_str) {
                                chat_str = allocate(2);
                                chat_str[0] = "The rattlesnake hisses.\n";
                                chat_str[1] = "The rattlesnake rattles.\n";
						 
                                
                         }
                         load_chat(3, chat_str); 
   
}