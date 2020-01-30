inherit "obj/monster";

reset(arg) {
    object armour;
    ::reset(arg);
    if(arg) { return; }
    set_level(1+random(5));
    set_name("guglah");
    set_alias("monster");
    set_short("A "+({ "giant", "small", "baby", "medium", "stupid", "dirty",})[random(6)]+" guglah staring at your with eyes gleaming!");
    set_long("Guglah is one of the unknown and forgotten race that lives underground\n"+
             "the city, but for a some reason these cruel monsters have climb up from the city and\n"+
             "started to terrorize the city by killing everything that moves and destroying \n"+
             "everything that doesn't move.\n");
    set_al(-10);
    set_aggressive(1);
    set_block_dir(({"north", "west", "east", "south",})[random(4)]);
    set_animal(1);
}

