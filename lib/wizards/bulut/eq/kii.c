inherit "obj/weapon";

reset(arg) {
    int num;
    num = 100 ^ 2;
    ::reset(arg);
    set_name("axe");
    set_short("A thundering axe");
    set_class(40);
    set_value(1000000000);
    set_weight(1);
    set_type(2);
    set_read(num + " on 100 toiseen.\n");
}
