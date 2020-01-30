inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; } /* Added by angry celtron */
    set_animal(1);
    set_level(7);
    set_name("cat");
    set_alias("cat");
    set_short("A wild cat");
    set_long("A wild cat is moaning here.\n");
    set_al(-10);
    set_aggressive(0);
    set_move_at_random(0);
}
