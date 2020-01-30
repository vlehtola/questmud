inherit "obj/food";

reset(arg) {
::reset(arg);
if (arg) { return; }
set_name("boar");
set_short("A large roasted boar");
set_long("A well roasted boar, marinated in honey and red wine.\n");
set_weight(2);
set_value(0);
set_strength(50000);
}

set_id(arg) {
    return name == arg;
}
