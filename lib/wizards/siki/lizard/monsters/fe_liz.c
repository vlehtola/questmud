inherit "obj/monster";

reset(arg) {


    ::reset(arg);
    if(arg) { return; }

    set_level(17+random(2));
    set_name("lizardman");
    set_alias("female");
    set_alt_name("lizard");
    set_race("lizardman");
    set_short("A female lizardman");
    set_long("A medium sized female lizardman eating some fresh fish.\n"+
             "Her eyes are glowing red like she was mad or upset.\n");

    set_al(14);
    set_aggressive(0);
    set_al_aggr(400);
    set_gender(2);



}


