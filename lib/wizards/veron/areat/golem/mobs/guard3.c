inherit "obj/monster";

reset(arg) {

    string chat_str;
    object armour,scimitar;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
 set_race("human");
    set_level(random(10)+27);
    set_str(query_str()+10);
    set_str(query_con()+20);
    set_name("guard");
    set_alias("human");
    set_short("An angry-looking guard");
    set_long("This guard looks aware. He stands still and \n"+
             "watches your every move carefully.\n");
             
    set_al(10);
    set_aggressive(0);
    
   armour = clone_object("/wizards/veron/areat/golem/items/chainmail");
    move_object(armour, this_object());
    init_command("wear mail");      
   scimitar = clone_object("/wizards/veron/areat/golem/items/scimitar");
    move_object(scimitar, this_object());
    init_command("wield scimitar");     


                        if (!chat_str) {
                                chat_str = allocate(3);
                                chat_str[0] = "The guard asks 'What's your business here?\n";
                                chat_str[1] = "The guard says 'Get out of here while you can still walk!\n";
                                chat_str[2] = "The guard says 'Get lost!'\n";

                         }
                         load_chat(3, chat_str); 

   
}