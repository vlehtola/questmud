inherit "obj/food";

reset(arg) {
::reset(arg);
if (arg) { return; }
set_name("ham");
set_short("A chunk of ham");
set_long("It looks juicy and well cooked.\n");
set_weight(3);
set_value(0);
set_strength(100000);
}

set_id(arg) {
    return name == arg;
}

