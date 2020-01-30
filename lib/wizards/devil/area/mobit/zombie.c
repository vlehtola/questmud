inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_level(50);
    set_name("zombie");
    set_alias("zombie");
    set_undead(1);
    set_short("A zombie rising from the grave");
    set_long("A zombie is rising from the old grave. The zombie\n"+
                      "looks like it has been under the surface of the earth about\n" +
                      "for thousands of years. Zombie slobbers as it notices you\n" +
                      "and starts to crawl at you like it want to eat you.\n");    
    set_al(-100);
    set_aggressive(0);
    
}
