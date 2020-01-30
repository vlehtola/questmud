inherit "obj/monster";

reset(arg) {


    ::reset(arg);
    if(arg) { return; }
    
    set_level(20+random(10));
    set_name("lizardman");
    set_alias("elder");
    set_alt_name("lizard");
    set_race("lizardman");
    set_short("An old lizardman");
    set_long("An old and wise lizardman. His scales have dropped in the past\n"+
             "few years.\n");
             

    set_al(20);
    set_aggressive(0);
    set_al_aggr(400);
    set_gender(1);



}


