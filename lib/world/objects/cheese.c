inherit "obj/food";

reset(arg) {
::reset(arg);
if (arg) { return; }
set_name("cheese");
set_short("A piece of old cheese");
set_long("This cheese is old but edible.\n");
set_weight(1);
set_value(0);
set_strength(20000);
}

set_id(arg) {
    return name == arg;
}

