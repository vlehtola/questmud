inherit "obj/base_object";
 
reset(arg) {
::reset(arg);
if (arg) { return; }
set_name("brick");
set_alias("tiili0407432002");
set_short("A brick");
set_long("This is brick.\n");
set_weight(1);
set_value(1);
set_no_get(1);
}
 
set_id(arg) {
    return name == arg;
}
