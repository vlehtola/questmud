inherit "obj/food";

reset(arg) {
::reset(arg);
if (arg) { return; }
set_name("rice");
set_alias("bowl");
set_short("A bowl of rice (by walla)");
set_long("Is very good. Walla made it.\n");
set_weight(1);
set_value(0);
set_strength(20000);
}

set_id(arg) {
    return name == arg;
}
