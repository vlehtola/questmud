inherit "/obj/monster";

object ob;

reset(arg) {
    string chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(5);
    set_name("rat");
    set_short("A rat is lurking in the corner");
    set_long("A rat\n");
    set_al(0);
    set_aggressive(0);
    set_gender(0);
    set_race("animal");
        chat_str = allocate(1);
         chat_str[0] =
          "Rat goes 'Squeek!'\n";
    load_chat(5, chat_str);

}               

                                                               