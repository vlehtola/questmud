inherit "/obj/monster";

object ob;

reset(arg) {
    string chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(15);
    set_name("caretaker");
    set_alias("man");
    set_short("Graveyards caretaker, sitting on the bench");
    set_long("This man looks very old, he has probably sat here for ages.\n");
    set_al(0);
    set_aggressive(0);
    set_gender(1);
    set_race("human");
        chat_str = allocate(3);
         chat_str[0] =
          "Caretaker whines: I dont have the strength to keep this place up anymore.\n";
        chat_str[1] =
          "Caretaker says: Nobody visits the people resting here anymore.\n";
        chat_str[2] =
          "Caretaker whispers: I have heard strange noises, coming from the ground.\n";
    load_chat(15, chat_str);

}               

                                                               