inherit "obj/monster";
reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_level(150);
    set_name("human");
    set_alias("human");
    set_short("A human hunter stalking here.(BOT KILLER)");
    set_long("Rusty bot killer. Tweek tweek skriiiks poks.\n");
   

}
