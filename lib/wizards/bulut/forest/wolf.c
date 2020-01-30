inherit "obj/monster";

reset(arg) {

    ::reset(arg);
    if(arg) { return; }
    set_animal(1);
    set_level(18);
    set_name("wolf");
    set_alias("wolf");
    set_short("A large wolf");
    set_long("A large wolf is planning to eat you.\n");
    set_al(-10);
    set_aggressive(0);
    set_move_at_random(0);
}
