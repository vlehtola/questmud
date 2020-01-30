inherit "obj/monster";

reset(arg) {
        ::reset(arg);
        if(arg) { return; }
        set_level(9);
        set_name("wolf");
        set_animal();
        set_short("A grey wolf is howling to the moon");
        set_long("The wolf is one of the most dangerous animals\n"+
                "in the forest. It has grey fur and it looks very\n"+
                "noble. It seems to know that other animals fear\n"+
                "it. It has sharp teeth and claws.\n");
        set_al(0);
        set_aggressive(0);
}
