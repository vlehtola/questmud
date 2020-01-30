inherit "obj/monster";

reset(arg) {
    int i;
    object weapon;
    ::reset(arg);
    if(arg) { return; }
    
    i = random(3);
    set_level(20+random(3)+i*3);
    set_name("giant");
    set_alias("male");
    set_exp(query_exp()*0.8);
    set_race("giant");
    if(i == 0) set_short("A small male giant");
    if(i == 1) set_short("A medium male giant");
    if(i == 2) set_short("A large male giant");
    set_long("A strong male giant. His arms are very powerful and he\n"+
             "could easily crush a weak opponent.\n");
             
    set_al(0);
    set_aggressive(0);
    set_al_aggr(400);
    set_gender(1);

    weapon = clone_object("/wizards/siki/island/eq/club");
    move_object(weapon,this_object());
    init_command("wield club");

}
