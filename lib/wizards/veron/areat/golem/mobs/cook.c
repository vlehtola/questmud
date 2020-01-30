inherit "obj/monster";

reset(arg) {
    string chat_str;
    object armour,pin;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_race("human");
    set_level(random(3)+25);
    set_max_hp(query_hp()+random(5000));
    set_name("cook");
    set_alias("human");
    set_short("A fat cook");
    set_long("This cook surely is fat. He's wearing a cooking apron\n"+
             "and is currently working with some dough.\n");
             
    set_al(10);
    set_aggressive(0);
    
   armour = clone_object("/wizards/veron/areat/golem/items/apron");
    move_object(armour, this_object());
    init_command("wear apron");      
   pin = clone_object("/wizards/veron/areat/golem/items/pin");
    move_object(pin, this_object());
    init_command("wield pin");      

if (!chat_str) {
                                chat_str = allocate(2);
                                chat_str[0] = "The cook swings his rolling pin.\n";
                                chat_str[1] = "The cook adds some flour to the plough.\n";
                                
                         }
                         load_chat(2, chat_str); 

   
}