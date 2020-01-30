inherit "obj/monster";
reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_name("dwarf shopper");
    set_level(35);
    set_exp(235800);
    set_str(300);
    set_dex(300);
    set_con(300);
    set_int(300);
    set_wis(300);
    set_gender(1);
    set_alias("dwarf");
    set_short("A dwarven shopkeeper");
    set_long("Very beautifully dressed dwarf has a long black cape.\n"+
             "Dwarf has some sort of list in his hand.\n"+
             "Maybe you should type <Items> to see what he offers.\n");
    set_al_aggr(200);
    set_race("dwarf");
}
