inherit "obj/monster";

reset(arg) {

    ::reset(arg);
    if(arg) { return; }
    set_animal(1);
    set_level(8);
    set_name("snake");
    set_alias("snake");
    set_short("A small snake");
    set_long("A small snake is crawlin here.\n");
    set_al(-10);
    set_aggressive(0);
    set_move_at_random(0);
}
