inherit "/wizards/siki/base_drink";

reset(arg) {
	::reset();
    if (arg)
    return;
	set_name("fountain");
	set_short("A fountain full of water");
	set_long("A beautiful fountain made from white marble which is full of decorations and pictures. A fresh looking water is constantly flowing from the hands of small statue");
	set_extra_long("Thirsty adventurers may 'drink' from it");
	set_weight(10000);
	set_no_drop(1);
	set_no_get(0);
	set_can_label(0);
	set_max_drinks(1);
	set_liquid_type("water");
}

do_drink() {
  write("The bubbles tickle your nose, as you take a deep gulp.\n");
  say(this_player()->query_name()+" takes a deep gulp from fountain.\n");
  this_player()->drink_soft(100000);
  return 1;
}

query_drinks_left() { return 1; }
