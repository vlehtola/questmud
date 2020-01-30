inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_name ("guard");
    set_level (30);
    set_gender(1);
    set_al(20);
    set_alias("guard");
    set_race("human");
    set_short("Guard is here watching the castle by the gate.");
    set_long("This guard seems to be bored since there hasn't been any attacks lately.\n");
    set_aggressive(0);

}