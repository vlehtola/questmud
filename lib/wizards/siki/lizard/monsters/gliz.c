inherit "obj/monster";

reset(arg) {


    ::reset(arg);
    if(arg) { return; }
    
    set_level(25+random(5));
    set_name("lizardman");
    set_alias("male");
    set_alt_name("lizard");
    set_race("lizardman");
    set_short("A huge lizardman");
    set_long("A huge male lizardman wandering around. He seems to look\n"+
             "for something. \n");

    set_al(14);
    set_aggressive(0);
    set_al_aggr(400);
    set_gender(1);



}


