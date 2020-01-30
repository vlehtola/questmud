inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_name ("boy");
    set_level (15);
    set_gender(1);
    set_al(20);
    set_alias("boy");
    set_race("human");
    set_short("Boy is playing here with his toys.");
    set_long("This boy plays his games with unbelieveable delight and he seems to enjoy his it.\n");
    set_aggressive(0);
}