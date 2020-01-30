inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_name ("cleric");
    set_level (50); 
    set_str(query_str()*2);
    set_al(20);
    set_gender(2);
    set_alias("cleric");
    set_race("human");
    set_short("Cleric is healing wounded knights here.");
    set_long("This cleric looks like she knows what she is doing. Knight after knight has been recovered by her hands.\n");
    set_aggressive(0);
}