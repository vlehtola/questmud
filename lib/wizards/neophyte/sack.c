inherit "/wizards/neophyte/container";

reset(arg) {
	::reset();
   if (arg)
   return;
	set_name("sack");
	set_short("A medium sized leather sack");
	set_long("The sack is made from leather and it is quite usefull to carrying things");
	set_size(5); /* This must be 1-10*/
}
