inherit "/obj/monster";

object ob;

reset(arg) {
    string chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(5);
    set_name("crow");
    set_short("A pitch black crow, standing still");
    set_long("A pich black crow, never seen crow before?\n");
    set_al(-10);
    set_aggressive(0);
    set_gender(1);
    set_race("animal");
        chat_str = allocate(1);
         chat_str[0] =
          "Crow goes 'Kraaaak'\n";
    load_chat(15, chat_str);

}               

                                                               