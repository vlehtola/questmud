inherit "obj/monster";

reset(arg) {
    ::reset(arg);
if (arg) { return; }
    set_level(40);
    set_name("knight");
    set_alias("assassin");
    set_short("An assassin knight");
    set_long("An hostile looking assassin knight protects the Master Knight. He is very quick and\n"+
             "clever. His eyes are red. He is quite small but muscular. He looks very angry and\n"+
             "loyal.\n");

    set_al(-10);
    set_gender(1);
    set_race("human");
    set_aggressive(1);
}









