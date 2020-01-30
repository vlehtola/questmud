string name, us_desc, ul_desc, s_desc, l_desc;
int quality, i;
status id;

drop() { return 0; }
get() { return 1; }
query_weight() {  return quality*2; }
query_herb() { return this_object(); }
query_name() { return name; }
id(str) { return str == name || str == "herb"; }
query_long() { if(!id) { return ul_desc; } else { return l_desc+"It is "+call_other("/guilds/witch/obj/potion_d", "get_quality", quality)+" quality\n."; } }
short() { if(!id) { return us_desc; } else { return s_desc; } }
long() { if(!id)  { write(ul_desc+"\n"); } else { write(l_desc+"It is "+call_other("/guilds/witch/obj/potion_d", "get_quality", quality)+" quality.\n"); } }

set_quality(int x) {
	quality = x;
	if(quality > 100)quality = 100;
	if(this_player()->query_skills("identify herb") < random(quality)) {
		us_desc = "A strange looking herb"; ul_desc = "A strange looking herb.\nMaybe you should identify it."; id = 0;
	return 1;
	}
	id = 1;
}
query_quality() { return quality; }
query_identify() { return id; }

set_identify(int i) {
	id = 1;
}

herbs() { return this_object(); }
dest_me() { destruct(this_object()); }
