inherit "obj/monster";

reset(arg) {


    ::reset(arg);
    if(arg) { return; }
    
    set_level(10+random(3));
    set_name("orc slave");
    set_alias("slave");
    set_race("orc");
    set_short("A weak orc slave");
    set_long("A small orc looking extremely tired. He has whip marks all\n"+
             "over his body and his left arm is bleeding badly. His ribs can\n"+
             "be seen through his skin.\n");

    set_al(0);
    set_aggressive(0);
    set_al_aggr(200);
    set_gender(1);



}

