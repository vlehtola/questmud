inherit "obj/food";

reset(arg) {
::reset(arg);
if (arg) { return; }
set_name("sandwich");
set_short("A small seaweed sandwich");
set_long("A small sandwich, filled with seaweed found on corel rifts.\n");
set_weight(1);
set_value(0);
set_strength(15000);
}

set_id(arg) {
    return name == arg;
}
