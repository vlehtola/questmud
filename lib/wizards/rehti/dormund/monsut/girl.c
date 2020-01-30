inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_name ("girl");
    set_level (15);
    set_gender(2);
    set_al(20);
    set_alias("girl");
    set_race("human");
    set_short("Girl is playing here with her toys.");
    set_long("This girl plays with her dolls.\n");
    set_aggressive(0);
}