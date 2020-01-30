inherit "obj/weapon";
 
reset(arg) {
    ::reset(arg);
    set_name("sword");
    set_alias("sword");
    set_short("Sharp sword");
    set_long("This sword belongs to the guard of cannibal king.\n",
             "This is very sharp sword.\n");
    set_wc(30);
    set_weapon_type("blade");
    set_value(500);
    set_weight(300);
}
