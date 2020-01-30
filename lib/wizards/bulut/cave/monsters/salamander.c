inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; } /* Added by angry celtron */
    set_animal(1);
    set_level(25);
    set_name("salamander");
    set_alias("ugly");
set_short("An ugly salamander");
    set_long("An ugly salamander is looking at you.\n");
    set_al(-10);
    set_aggressive(0);
   set_move_at_random(10);
    set_animal(1);
    set_skill_chance("kick", 100);
}
