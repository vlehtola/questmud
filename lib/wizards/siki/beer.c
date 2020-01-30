inherit "/wizards/siki/base_drink";

reset(arg) {
	::reset();
    if (arg)
    return;
	set_name("beer");
	set_alias("bottle");
	set_short("A bottle of karhu");
	set_long("A brown bottle of karhu named beer");
	set_prevent_insert();
	set_prevent_insert_message("You don't want to ruin the "+name+"");
	set_weight(100);
	set_value(10);
	set_no_drop(0);
	set_no_get(1);
	set_no_save(1);
	set_can_label(1);
	set_max_drinks(5);
	set_can_fill(1);
	set_drink_message("That tasted like honey");
	set_last_drink_message("You take the last sip from "+name+"");
	set_liquid_type("beer");
}
