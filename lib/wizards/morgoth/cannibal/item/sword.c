inherit "obj/weapon";
 
reset(arg) {
    ::reset(arg);
    set_name("Bloodred sword called Flesh Eater");
    set_alias("sword");
    set_short("Bloodred sword called Flesh Eater");
    set_long("This sword belongs to king of the cannibals.\n",
             "Blade of this sword is very sharp and it seems to be magical.\n");
    set_wc(60);
    set_weapon_type("blade");
    set_value(40000);
    set_weight(300);
}
