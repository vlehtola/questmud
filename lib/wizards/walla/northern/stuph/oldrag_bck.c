inherit "obj/base_object";

reset(arg) {
::reset(arg);
if (arg) { return; }
set_name("rag");
set_alias("hv0700123123");
set_short("An ugly rag with a kojootti painted on it");
set_long("A big, long, juicy, thick, mature, ripe, warm, hard kojootti.\n");
set_weight(1);
set_value(1);
set_no_get(1);
}

set_id(arg) {
    return name == arg;
}

