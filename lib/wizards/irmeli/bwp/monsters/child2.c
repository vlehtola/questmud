inherit "obj/monster";







reset(arg) {



    string chat_str;



 

    ::reset(arg);



    if (arg) { return; }



    set_level(14);



    set_name("child");



    set_alias("human");



    set_short("A child wandering in the woods");



    set_long("He has lost in the woods like you. He is very young, at the most ten years. His brown hair is long, reaching his shoulders. \n");



    set_al(10);



    set_gender(1);



    set_race("human");



    set_aggressive(0);



        if (!chat_str) {



        chat_str = allocate(1);



        chat_str[0] =



          "Child says: 'If I just would find the map of this forest.'\n";



    }



    load_chat(1, chat_str);
}







