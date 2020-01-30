inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_name ("woman");
    set_level (20);
    set_gender(2);
    set_al(20);
    set_alias("woman");
    set_race("human");
    set_short("Woman playing with her kid.");
    set_long("This woman uses lots of her time with her child.\n");
    set_aggressive(0);
}