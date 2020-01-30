inherit "obj/armour";

start() { 
    set_class(2);
    set_name("ring");
    set_short("A bluish ring");
    set_long("It is a blue ring. It is very smooth and has a\n" +
                    "beautiful shape. It could be of divine make");
    set_stats("int", -2);
    set_stats("str", 2);
    set_weight(50);
    set_value(200);
    set_slot("finger");
}
