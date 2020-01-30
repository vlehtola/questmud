inherit "obj/monster";

reset(arg) {
    string chat_str;
    object armour,scimitar;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_race("human");
    set_level(random(10)+20);
    set_str(query_str()+10);
    set_str(query_con()+20);
    set_name("guard");
    set_alias("human");
    set_short("A bored-looking guard");
    set_long("This young guard looks extremely bored. He leans to the wall and\n"+
             "looks idle. He's wearing a worn chainmail and is wielding \n"+
 		 "a scimitar in his hand.\n");
             
    set_al(10);
    set_aggressive(0);
    
   armour = clone_object("/wizards/veron/areat/golem/items/chainmail");
    move_object(armour, this_object());
    init_command("wear mail");      
   scimitar = clone_object("/wizards/veron/areat/golem/items/scimitar");
    move_object(scimitar, this_object());
    init_command("wield scimitar");     

                 if (!chat_str) {
                                chat_str = allocate(2);
                                chat_str[0] = "The guard sniffs.\n";
                                chat_str[1] = "The guard yawns.\n";
						 
                                
                         }
                         load_chat(3, chat_str); 
   
}