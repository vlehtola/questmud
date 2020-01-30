inherit "obj/monster";
reset(arg) {
    object armour;
    object weapon;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_level(666);
    set_exp(1000000000);
    set_hp(120000);
    set_max_hp(120000);
    set_sp(140000);
    set_max_sp(140000);
    set_ep(10000);
    set_max_ep(10000);
    set_name("dragon");
    set_alias("dragon");
    set_short("Belar's pet dragon");
    set_long(" It's a dragon. RUN for your life!\n");
    set_al_aggr(30);
    set_animal(1);

    }
