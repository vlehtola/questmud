inherit "obj/monster";

reset(arg) {
        ::reset(arg);
        if(arg) { return; }
        set_level(7);
        set_name("deer");
        set_animal();
        set_short("A slender deer is here");
        set_long("The deer is the favourite prey of many\n"+
                "vicious animals. It has brown fur and small\n"+
                "antlers. Is is constantly looking out for it's\n"
                "natural enemies.\n");
        set_al(0);
        set_aggressive(0);
}
