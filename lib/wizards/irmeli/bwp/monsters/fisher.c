inherit "obj/monster";







reset(arg) {



    string chat_str;




    ::reset(arg);



    if (arg) { return; }



    set_level(15);



    set_name("fisher");



    set_alias("human");



    set_short("A fisher telling fishing stories");



    set_long("A fisher was years ago a great fisherman. He lost his boat on a storm and barely escaped with his live. That boat was source means of livelihood for him.\n");



    set_al(10);



    set_gender(1);



    set_race("human");



    set_aggressive(0);



        if (!chat_str) {



        chat_str = allocate(1);



        chat_str[0] =



          "Fisher says: 'That fish i got last week as a big one.'\n";



    }



    load_chat(1, chat_str);
}








