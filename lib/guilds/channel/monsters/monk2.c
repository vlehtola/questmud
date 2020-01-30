inherit "obj/monster";
   
string chat_str;

reset(arg) {

    ::reset(arg);
    if(arg) { return; }

    set_level(5+random(2));
    set_name("monk");
    set_race("human");
    set_short("An old and bitter monk");
    set_long("This old monk has a long beard and a hairy body. He doesn't look\n"+
             "happy at all and he is full of hate which is very unusual for a monk.\n");


    set_al(30);
    set_aggressive(0);
    set_al_aggr(400);
    set_move_at_random(30);
    set_gender(1);
     if (!chat_str) {
        chat_str = allocate(2);
    chat_str[0] = "The monk says 'All my life I have served Cyral and what have I got? Nothing!'\n";
    chat_str[1] = "The monk says 'Someday I will burn this church.' and spits on the ground.\n";

       }
    load_chat(7, chat_str); 
 
 }
