inherit "obj/monster";
   
reset(arg) {

    ::reset(arg);
    if(arg) { return; }

    set_level(2+random(2));
    set_name("monk");
    set_race("human");
    set_short("A devout monk");
    set_long("A extremely religious monk wandering in the church. He has found the truth\n"+
             "he was looking for and has now devoted his life to his God, Cyral.\n");


    set_al(30);
    set_aggressive(0);
    set_move_at_random(18);
    set_al_aggr(400);
    set_gender(1);
 
 }
