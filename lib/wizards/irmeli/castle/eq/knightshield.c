inherit "obj/weapon";
start () {
set_class(7);
set_sub_type("large shield");
    set_name("shield");
    set_short("Black shield of Knights");
    set_long("The black shield of Knights is made of titanium. It's large and gives good\n"+
             "protection. A knight riding on a horse has been drawed on the shield.\n"+
             "The handle is made of iron.\n");
    set_resists("fire", 5);
    set_resists("physical", 5);
    set_resists("cold", 5);
}
