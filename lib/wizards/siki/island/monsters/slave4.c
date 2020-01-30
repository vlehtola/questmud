inherit "obj/monster";


object weapon;
reset(arg) {


    ::reset(arg);
    if(arg) { return; }

    set_level(14+random(3));
    set_name("orc slave");
    set_alias("slave");
    set_race("orc");
    set_exp(query_exp()*1.7);
    set_short("An extremely tired orc slave");
    set_long("A strong but starving orc slave working here in the mines. His ribs\n"+
             "can be seen through his dirty skin. He has large bruises all over\n"+
             "his body.\n");

    set_al(0);
    set_aggressive(0);
    set_al_aggr(200);
    set_gender(1);


    weapon = clone_object("/wizards/siki/island/eq/pick");
    move_object(weapon,this_object());
    init_command("wield axe");


}
