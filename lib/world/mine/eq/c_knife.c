inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
    set_name("curved knife");
    set_alias("knife");
    set_short("A curved knife");
    set_long("The knife is made of steel. Its blade is slightly curved\n" +
             "and it looks quite sharp.\n");
    set_class(10);
    set_weight(1);
    set_type(6);
    set_value(100);
}
