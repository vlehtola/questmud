inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_level(100);
    set_name("monk");
    set_alias("herman");
    set_short("Herman, the runemaster of the monastery");
    set_long("A very old and fat monk. His hands have lots of ink stains on them and \n" +
             "his robes look very new. He is radiating some strange aura of authority.\n");
    set_al(50);
    set_aggressive(0);
}

