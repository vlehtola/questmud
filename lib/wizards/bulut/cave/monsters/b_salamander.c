inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; } /* Added by angry celtron */
    set_animal(1);
    set_level(15);
    set_name("salamander");
    set_alias("baby");
    set_short("A baby salamander");
    set_long("An ugly baby salamander is looking at you.\n");
    set_al(-10);
    set_aggressive(0);
    set_move_at_random(10);
    set_animal(1);
    set_skill_chance("kick", 100);
}





