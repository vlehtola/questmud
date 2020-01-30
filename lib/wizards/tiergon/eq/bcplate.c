inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_name("breastplate");
    set_alias("armour");
    set_short("A dark adamantine breastplate");
    set_long("This breastplate has been made from black admantine. The breast and back plates are kept together by chimera leather straps.\n"); 
    set_ac(35);
    set_value(1666);
    set_weight(400);
    set_slot("torso");
}
