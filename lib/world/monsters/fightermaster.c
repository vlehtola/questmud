inherit "obj/monster";
reset(arg) {

::reset(arg);
if (arg) { return; }
    set_level(100);
    set_name("master");
    set_alias("fightermaster");
    set_short("A Fightermaster");
    set_long("\n"+
             "\n"+
             "\n");

    set_race("human");
    set_gender(1);
    set_al(20);
    set_aggressive(0);

 }









