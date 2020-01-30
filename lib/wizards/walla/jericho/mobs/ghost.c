inherit "obj/monster";
 
reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_level(35+random(10));
    set_str(query_str() + 250);
    set_dex(query_dex() + 200);
    set_max_hp(query_hp() -1000);
    set_name("ghost");
    set_alias("undead");
    set_mage(1,2);
    set_short("A ghost (undead)");
    set_long("You have unleashed a creature, long buried. It doesn't seem to appreciate the fact\n"+
             "that you have awoken it from it's eternal sleep.\n");
    set_al(-200);
    set_gender(2);
    
    
}
