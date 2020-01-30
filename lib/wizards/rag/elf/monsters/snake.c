inherit "obj/monster";

reset(arg) {
        ::reset(arg);
        if(arg) { return; }
        set_level(5);
        set_name("snake");
        set_animal();
        set_short("A snake slithers in the bushes");
        set_long("This snake is green and black. It has a\n"+
                "saw-pattern on it's back. Is isn't very big\n"+
                "and it doesn't look poisonous.\n");
        set_al(0);
        set_aggressive(0);
}
