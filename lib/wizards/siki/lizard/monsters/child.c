inherit "obj/monster";

reset(arg) {


    ::reset(arg);
    if(arg) { return; }
    
    set_level(10+random(2));
    set_name("lizardman");
    set_alias("child");
    set_alt_name("lizard");
    set_race("lizardman");
    set_short("A little lizardman playing with a dead fish");
    set_long("This cute little lizardman is so innocent and doesn't know\n"+
             "anything about the cruel world. He is laughing and enjoying\n"+
             "life.\n");

    set_al(20);
    set_aggressive(0);
    set_al_aggr(400);
    set_gender(1+random(2));



}

