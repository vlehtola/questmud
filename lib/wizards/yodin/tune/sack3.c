inherit "/obj/container";
query_no_save()  { return 1; }
reset(arg) {
	::reset();
   if (arg)
   return;
	set_name("sack");
	set_short("A very small sized leather sack");
	set_long("The sack is made from leather and it is quite usefull to carrying things");
	set_size(2); /* This must be 1-10*/
}
