inherit "obj/monster";

reset(arg) {
    string chat_str;
   
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_undead(1);
    set_level(random(3)+20);
    set_str(query_str()+20);
    set_str(query_con()+30);
    set_name("skeleton");
    set_alias("horse");
    set_short("A horse skeleton");
    set_long("A skeleton of a large steed. The skeleton stands still and\n"+
             "swings it's tailbones. There's a battered and worn saddle on\n"+
 	     "it's back\n");
           
             
    set_al(0);
    set_aggressive(0);
    set_animal(1);
  

                 if (!chat_str) {
                                chat_str = allocate(2);
                                chat_str[0] = "The horse swings it's tail.\n";
                                chat_str[1] = "The skeleton makes a crackling sound.\n";
						 
                                
                         }
                         load_chat(3, chat_str); 
   
}