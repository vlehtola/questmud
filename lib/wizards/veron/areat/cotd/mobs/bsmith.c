inherit "obj/monster";

reset(arg) {
    string chat_str;
    object armour,scimitar;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_undead(1);
    set_level(random(10)+35);
    set_str(query_str()+30);
    set_str(query_con()+30);
    set_name("blacksmith");
    set_alias("smith");
    set_short("A muscular blacksmith");
    set_long("The huge, dark-skinned blacksmith is an impressive-looking man\n"+
             "with his muscular hands. He's been dead for at least a week and\n"+
 	     "the color of his skin has started to have a touch of green. Some\n"+
             "chunks of flesh have already fell off his shoulders.\n");
             
    set_al(-10);
    set_aggressive(0);
    
   armour = clone_object("/wizards/veron/areat/golem/items/chainmail");
    move_object(armour, this_object());
    init_command("wear mail");      
   scimitar = clone_object("/wizards/veron/areat/golem/items/scimitar");
    move_object(scimitar, this_object());
    init_command("wield scimitar");     

                 if (!chat_str) {
                                chat_str = allocate(2);
                                chat_str[0] = "The blacksmith moans.\n";
                                chat_str[1] = "The blacksmith mumbles 'G-gget o-outta he-rrre'.\n";
						 
                                
                         }
                         load_chat(3, chat_str); 
   
}