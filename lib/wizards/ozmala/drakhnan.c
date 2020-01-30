inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) {return; }
    set_name("drakhnan");
    set_level(1);
    set_exp(66351570);
    set_al(100);
    set_gender(1);
    set_race("troll");
    set_short("Drakhnan the mighty leader of trolls");
    set_long("blaa.\n");
    set_aggressive(0);
    set_move_at_random(0);
    set_log();

}
