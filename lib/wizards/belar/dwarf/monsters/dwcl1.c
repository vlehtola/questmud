inherit "obj/monster";
reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_name("dwarf");
    set_level(45);
    set_exp(2358000);
    set_str(300);
    set_dex(300);
    set_con(300);
    set_int(300);
    set_wis(300);
    set_gender(1);
    set_alias("dwarf");
    set_short("A Dwarf is selling clerical services");
    set_long("Very elegantly dressed dwarf has a long white cape.\n"+
             "Dwarf has some sort of list in his hand.You can sense his wisdom\n"+
             "Maybe you should type <Clerical> to see what he offers.\n");
    set_al_aggr(100);
    set_race("dwarf");
}
