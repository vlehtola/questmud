inherit "/obj/container";

reset(arg) {
	::reset();
   if (arg)
   return;
	set_name("sack");
	set_short("A huge sized leather sack");
	set_long("The sack is made from leather and it is quite usefull to carrying things");
	set_size(10); /* This must be 1-10*/
}
