inherit "obj/monster";
 
reset(arg) {
    object armour;
    ::reset(arg);
    if (arg) { return; }
    set_level(35);
    set_name("snake");
    set_short("A huge and long snake");
    set_long("It seems to be very angry at YOU.\n");
    set_al(-10);
    set_mage(1);
    set_aggressive(1);
    set_animal(1);

    armour = clone_object("/wizards/grathlek/area1/eq/cross.c");  
    move_object(armour, this_object());
}
