inherit "obj/monster";

reset(arg) {
    object armour;
    ::reset(arg);
    if(arg) { return; }
    set_level(1);
    set_name("I tiny cat called Errtu");
    set_alias("Cat");
    set_short("A tiny cat called Errtu");
    set_long("A small cute cat\n");
    set_al(10);
    set_aggressive(0);
 /* Mark that the monster is an animal: */
    set_animal(1);
}


