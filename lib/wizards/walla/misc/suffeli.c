
inherit "obj/food";

reset(arg) {
reset(arg);
if (arg) { return; }
set_name("suffeli");
set_short("A suffeli");
set_long("Hmm.. it looks delicious.\n");
set_weight(1);
set_value(0);
set_strength(40000);
}

set_id(arg) {
return name == arg;
}
