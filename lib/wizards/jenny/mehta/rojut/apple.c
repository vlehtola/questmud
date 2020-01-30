inherit "obj/food";

reset(arg) {
::reset(arg);
if (arg) { return; }
set_name("apple");
set_short("An apple");
set_long("Delicious looking red apple\n");
set_weight(1);
set_value(0);
set_strength(20000);
}

set_id(arg) {
    return name == arg;
}
