inherit "obj/weapon";   
 
reset(arg) {
        ::reset(arg);
        set_name("saber");
        set_short("Light Saber");
        set_long("A Jedi Light Saber.");
        set_material(6);
        set_wc(69)
        set_weapon_type("blade");
        set_value(10);
        set_weight(5);
 
        set_stats("str", 1000);
        set_stats("con",1000);
        set_stats("dex",1000);
        set_stats("hpr",1000);
}
