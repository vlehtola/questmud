inherit "obj/food";

reset(arg) {
::reset(arg);
if (arg) { return; }
set_name("bread");
set_short("A piece of white bread");
set_long("Hmm.. it looks delicious.\n");
set_weight(2);
set_value(0);
set_strength(40000);
}

set_id(arg) {
    return name == arg;
}

