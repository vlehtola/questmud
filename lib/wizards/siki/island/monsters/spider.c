inherit "obj/monster";

reset(arg) {


    ::reset(arg);
    if(arg) { return; }

    set_level(10+random(3));
    set_name("spider");
    set_alias("furry spider");
    set_short("A furry spider");
    set_long("A furry and scary looking spider. It spins webs extremely fast and it\n"+
             "has a strange look in its six eyes. It looks hungry.\n");


    set_al(-30);
    set_aggressive(1);
    set_al_aggr(200);
    set_animal();



}
