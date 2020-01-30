//Command to visit a workroom, by Rag
cmd_visit(arg) {
	string path;
	if(!arg) {
  		write("Use: visit <wizard>\n");
  		return 1;
	}
	path = "/wizards/"+arg;
	if(file_size(path) != -2) {
		write("No such wizard.\n");
		return 1;
	}
	this_player()->move_player("X#"+path+"/workroom");
	return 1;
}