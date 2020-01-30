inherit "obj/monster";
   
     string chat_str;

reset(arg) {

    ::reset(arg);
    if(arg) { return; }

    set_level(1+random(2));
    set_name("monk");
    set_race("human");
    set_short("A drunken monk is stumbling here");
    set_long("A drunken monk stumbling around the room. He is very drunk and his\n"+
             "eyes are all red. A terrible smell of old booze emits from his clothes.\n");


    set_al(30);
    set_move_at_random(24);
    set_aggressive(0);
    set_al_aggr(400);
    set_gender(1);

     if (!chat_str) {
        chat_str = allocate(2);
    chat_str[0] = "The monk hiccups.\n";
    chat_str[1] = "The monk says 'I hope Cyral will not find out that I drink.'\n";

       }
    load_chat(6, chat_str); 

  }
