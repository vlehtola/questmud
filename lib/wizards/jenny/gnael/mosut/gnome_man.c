inherit "obj/monster";

reset(arg) {
    string chat_str;
    object shirt,trousers;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_race("gnome");
    set_level(random(3)+33);
    set_name("man");
    set_alias("pablo");
    set_short("A pleased looking gnomish man named 'Pablo'");
    set_long("Pablo, a pleased looking gnomish man, is humming\n"+ 
              "some unfamiliar tune while washing the dishes.\n"+
              "He is not very tall, but everything in his apartment\n"+ 
              "is small so he manages to live here just fine. He is\n"+
              "wearing a shirt and leather trousers.\n");
             
    set_al(2);
    set_aggressive(0);
   
   shirt = clone_object("/wizards/jenny/gnael/rojut/shirt");
    move_object(shirt, this_object());
    init_command("wear shirt");      
   
   trousers = clone_object("/wizards/jenny/gnael/rojut/trousers");
    move_object(trousers, this_object());
    init_command("wear trousers");         
 
                 if (!chat_str) {
                                chat_str = allocate(2);
                                chat_str[0] = "Pablo says: 'I like this city, even if there is a dark god here'\n";
                                chat_str[1] = "Pablo says: 'Mondasa does sometimes take a few souls, no big deal'\n";
                         }
                         load_chat(4, chat_str); 
}
