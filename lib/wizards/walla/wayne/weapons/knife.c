inherit "obj/weapon"; 
 
reset(arg) {
    ::reset(arg);
    set_name("knife");
    set_short("A f**king punk's throwing knife.\n");
    set_long("A knife.\n" +               
"As you press a button, the blade pops out\n");
    set_material(6);
    set_class(3);
    set_weapon_type("blade");
    set_value(5000);
    set_weight(2);
 
}

