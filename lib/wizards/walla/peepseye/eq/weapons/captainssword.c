inherit "obj/weapon";
 
reset(arg) {
    ::reset(arg);
    set_name("sword");
    set_short("A captain's sword");
    set_long("This sword is made out of some extraordinary material. It's handle is made out of \n" +
"bones and it seems to shine, eventhough it is almost dark outside.\n");
    set_class(20);
    set_weapon_type("blade");
    set_value(500);
    set_weight(600);
 
}

