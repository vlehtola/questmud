inherit "obj/base_object";

reset(arg) {
::reset(arg);
if (arg) { return; }
set_name("bone");
set_alias("luu123456");
set_short("A bone");
set_long("This bone has belonged to some living creature that has\n"+
         "died not too long ago. It still has some flesh on it");
set_weight(1);
set_value(1);
set_no_get(1);
}

set_id(arg) {
    return name == arg;
}
