cmd_drink(string str) {
	object what;
	string tmp;
	if(!str) { write("Drink what?\n"); return 1; }
	if(sscanf(str, "%s",tmp)==1) { }
	if(sscanf(str, "from %s",tmp)==1) { }
	what = present(tmp, environment(this_player()));
	if(!what) { what = present(tmp, this_player()); }
	if(!what) { write("You don't have such thing.\n"); return 1; }
	if(!what->can_be_drinked()) { write("You can't drink the "+capitalize(str)+".\n"); return 1; }
	if(!what->query_drinks_left()) { write("The "+capitalize(str)+" is empty.\n"); return 1; }
	what->do_drink();
	return 1;
}
