inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_name ("man");
    set_level (25);
    set_gender(1);
    set_al(20);
    set_alias("man");
    set_race("human");
    set_short("Man kissing with his wife.");
    set_long("This man seems to like playing with his wife.\n");
    set_aggressive(0);
}