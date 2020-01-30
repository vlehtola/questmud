inherit "obj/food";

reset(arg) {
::reset(arg);
if (arg) { return; }
set_name("bread");
set_short("A loaf of bread");
set_long("A freshly baked loaf of bread.\n");
set_weight(2);
set_value(21);
set_strength(40000);
}

set_id(arg) {
    return name == arg;
}
