inherit "obj/monster";

reset(arg) {
   

    ::reset(arg);
    if(arg) { return; }
    
    set_level(14+random(2));
    set_name("giant");
    set_alias("female");
  set_alt_name("female giant");
    set_race("giant");
    set_short("A female giant");
    set_long("A quite normal looking female giant. She has dirty long\n"+
             "hair and her skin is creased.\n");

    set_al(0);
    set_aggressive(0);
    set_al_aggr(400);
    set_gender(2);



}

