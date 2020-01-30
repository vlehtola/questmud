inherit "obj/food";

reset(arg) {
::reset(arg);
if (arg) { return; }
set_name("banana");
set_short("A peeled banana");
set_long("A big, long, peeled banana.\n");
set_weight(20);
set_value(1);
set_strength(21);
}

set_id(arg) {
    return name == arg;
}
