inherit "obj/monster";

reset(arg) {
    string chat_str;
    object armour,trousers,sword;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_race("dwarf");
    set_level(random(8)+28);
    set_name("glonk");
    set_alias("gatekeeper");
    set_short("Glonk Dwelder, a happy looking dwarf gatekeeper");
    set_long("Glonk Dwelder was a very famous smith about a\n"+ 
              "hundred years ago, but nowadays he is getting old and\n"+
              "is working for the city of Gnael as a gatekeeper. He\n"+
              "looks happy and is constantly smiling. Glonk is not very\n"+
              "tall, but like normally, dwarfs don't grow very tall. He\n"+
              "is wearing a leather armour and leather trousers and in his\n"+
              "right hand he is wielding a typical short sword.\n");
             
    set_al(3);
    set_aggressive(0);
   
   armour = clone_object("/wizards/jenny/gnael/rojut/leather_armour");
    move_object(armour, this_object());
    init_command("wear armour");      
   
   trousers = clone_object("/wizards/jenny/gnael/rojut/trousers");
    move_object(trousers, this_object());
    init_command("wear trousers");      

   sword = clone_object("/wizards/jenny/gnael/rojut/short_sword");
    move_object(sword, this_object());
    init_command("wield sword");     
 
                 if (!chat_str) {
                                chat_str = allocate(2);
                                chat_str[0] = "Glonk says: 'Please move so others can pass'\n";
                                chat_str[1] = "Glonk gives a smile to everyone\n";
                         }
                         load_chat(4, chat_str); 
}
