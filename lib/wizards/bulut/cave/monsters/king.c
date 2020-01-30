inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; } /* Added by angry celtron */
    set_animal(1);
    set_level(45);
    set_name("kerhma");
    set_alias("salamander");
    set_alt_name("king");
    set_short("Kerhma the salamander king");
    set_long("Youch! He sure is ugly.\n");
    set_al(-10);
    set_aggressive(0);
    set_move_at_random(0);
    set_wc(50);
    set_ac(40);
}
