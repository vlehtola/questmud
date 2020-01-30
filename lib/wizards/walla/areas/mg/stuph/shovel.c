inherit "obj/base_object";

reset(arg) {
::reset(arg);
if (arg) { return; }
set_name("shovel");
set_alias("shoveli212121");
set_short("A shovel");
set_long("This is an exquisite shovel.\n"+
         "On it is engraved 'you reap what you sow'");
set_weight(1);
set_value(1);
set_no_get(1);
}

set_id(arg) {
    return name == arg;
}

