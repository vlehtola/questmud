inherit "/wizards/siki/base_object";

reset(arg) {
	::reset();
    if (arg)
    return;
	set_name("test");
	set_short("This is da test �tem made by SIKI DA WIZ");
	set_long("DA long desc is this");
	set_extra_long("This is da extra long desc");
	set_prevent_insert();
	set_prevent_insert_message("This is just a test preventing insert of this object");
	set_weight(6000);
	set_value(50);
	set_no_drop(0);
	set_no_get(1);
	set_no_save(1);
	set_can_label(0);
	set_size(100);
	set_material("silk");
}
