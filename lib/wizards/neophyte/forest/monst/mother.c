inherit "obj/monster";

reset(arg) {
        ::reset(arg);
        if(arg) {return; }
        set_name("rabbit");
        set_alias("mother");
        set_level(3);
        set_gender(2);
        set_al(0);
        set_animal();
        set_short("A mother rabbit");
        set_long("She has a white fur and little dangled ears\n"+
                 "She is looking after little bunnies.\n");
}
