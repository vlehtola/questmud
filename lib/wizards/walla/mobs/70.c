inherit "obj/monster";
 
reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_level(70);
    set_name("citizen");
    set_alias("citizen");
    set_short("A citizen of Jericho");
    set_long("Almos all citizens of Jericho have been chased away\n"+
             "by Leb-Kamars army. The rest have been enslaved. Only\n"+
             "a few remain uncaptured. The citizen is very skinny, and\n"+
             "badly bruised.\n");
    set_al(0);
    set_gender(1);
    set_race("human");
 
 
}
