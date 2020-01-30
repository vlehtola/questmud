inherit "obj/monster";

reset(arg) {
        ::reset(arg);
        if(arg) { return; }
        set_level(6);
        set_name("fox");
        set_animal();
        set_short("A red fox with a furry tail");
        set_long("This fox is hunting small forest animals.\n"+
                "It is red and it has white-headed furry tail.\n"+
                "Although it isn't the biggest predator, it can\n"+
                "still be a nasty opponent. It is said to be the\n"+
                "smartest animal in the forest.\n");
        set_al(0);
        set_aggressive(0);
}
