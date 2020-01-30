inherit "obj/weapon";
start(){
	set_class(5);
	set_sub_type("maul");
	set_name("hammer");
	set_short("A dark blacksmith hammer");
	set_long("This hammer looks well beaten and old. The handle of hammer is\n"+
	         "blackened with soot and small traces of carbon can be seen of the\n"+
	         "surface of hammer.\n");
	set_max_dur(query_dur()+40);
	set_dur(query_max_dur());
	set_stats("damage", 9);
	set_stats("hit", 6);
	}
