cmd_bugs() {
	tail("/log/"+lower_case(this_player()->query_name() ) );
	return 1;
}