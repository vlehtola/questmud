
#define BUG_D "/daemons/bug_d"

cmd_bug(string str) {

int i;
object ob;
string name, report, path,tmp;

	if(!str) {
		if(this_player()->query_wiz() < 1) {
			write("syntax: bug <wizard's name / object in inventory or room / here> <report>\n");
			return 1;
		}
	write("Listing known bugs:\n");
	BUG_D->print_by_name(this_player()->query_real_name());
	return 1;
	}

	if(str == "all" && this_player()->query_wiz() > 0) {
		BUG_D->print_all_bugs();
		return 1;
	}
	
	if(sscanf(str,"%s %s",name, report) != 2) {
		write("syntax: bug <wizard's name / object in inventory or room / here> <report>\n");
		return 1;
	}
	
	if(name == "here") {
		name = creator(environment(this_player()));
		path = file_name(environment(this_player()));
		BUG_D->add_bug(name,path,report,this_player()->query_real_name(),ctime(time()));
		return 1;
	}
	
	if(present(name,this_player())) {
		ob = present(name,this_player());
		name = creator(ob);
		path = file_name(ob);
		if(path) sscanf(path,"%s#%d",path,tmp);
		report = "Object: "+ob->short()+"\n"+report;
		BUG_D->add_bug(name,path,report,this_player()->query_real_name(),ctime(time()));
		return 1;
	}
	
	if(present(name,environment(this_player()))) {
		
		
		ob = present(name,environment(this_player()));
		path = file_name(ob);
		if(path) sscanf(path,"%s#%d",path,tmp);
		name = creator(ob);
		report = "Object: "+ob->short()+"\n"+report;
		BUG_D->add_bug(name,path,report,this_player()->query_real_name(),ctime(time()));
		return 1;
	}
	if(name == "end") {
		write("Ending bug nro: "+report+"\n");
		i = to_int(report);
		BUG_D->remove_bug(i);
		return 1;
	}
	
	path = "none";
	BUG_D->add_bug(name,path,report,this_player()->query_real_name(),ctime(time()));
	return 1;	
}