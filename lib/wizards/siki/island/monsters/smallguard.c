inherit "obj/monster";

reset(arg) {


    ::reset(arg);
    if(arg) { return; }
    
    set_level(14+random(2));
    set_name("giant guard");
    set_alias("guard");
    set_race("giant");
    set_short("A small giant guard keeping discipline");
    set_long("A weak guard trying to keep discipline in the mines.\n"+
             "He is nervous and shivering of fear.\n");


    set_al(10);
    set_aggressive(0);
    set_al_aggr(200);
    set_gender(1);



}

