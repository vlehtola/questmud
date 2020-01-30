inherit "obj/monster";

reset(arg) {
        ::reset(arg);
        if(arg) { return; }
        set_name("nalle");
        set_level(100);
        set_short("A terrible NALLE");
        set_long("A fearsome and bloodthirsty NALLE roams here.\n");
        set_animal();
}
