inherit "obj/food";

reset(arg) {
::reset(arg);
if (arg) { return; }
set_name("noodles");
set_short("A steaming bowl of noodles");
set_long("A steaming bowl of delicious, oriental noodles.\n");
set_weight(2);
set_value(0);
set_strength(32000);
}

set_id(arg) {
    return name == arg;
}
