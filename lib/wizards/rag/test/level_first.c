inherit "obj/monster";

reset(arg) {
        ::reset(arg);
        if(arg) { return; }
        set_level(50);
        set_name("level_first");
        set_race("giant");
        set_short("This monster has level first");
        set_long("Level and then race, part of Rag's testing.\n");

}
