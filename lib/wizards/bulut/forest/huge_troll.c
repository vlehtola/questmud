inherit "obj/monster";

reset(arg) {

    ::reset(arg);
    if(arg) { return; }
    set_level(22);
    set_name("troll");
    set_alias("troll");
    set_short("A HUGE forest troll");
    set_long("A HUGE troll is lurking here.\n");
    set_al(-10);
    set_aggressive(0);
    set_move_at_random(0);
}
