
#define BUG_D "/wizards/astarel/daemons/bug_d"

cmd_bug(string str) {

int i;
object ob;
string name, report, path;

	if(!str) {
		if(this_player()->query_wiz() < 1) {
			write("syntax: bug <wizard's name / object in inventory or room / here> <report>\n");
			return ;
		}
	BUG_D->print_by_name(this_player()->query_real_name());
	return;
	}

	if(str == "all") {
		BUG_D->print_all_bugs();
		return;
	}
	
	if(sscanf(str,"%s %s",name, report) != 2) {
		write("syntax: bug <wizard's name / object in inventory or room / here> <report>\n");
		return;
	}
	
	if(name == "here") {
		name = creator(environment(this_player()));
		path = file_name(environment(this_player()));
		report = "ROOM: "+environment(this_player())->short() + report;
		BUG_D->add_bug(name,path,report,this_player()->query_real_name(),ctime(time()));
		return;
	}
	
	if(present(name,this_player())) {
		ob = present(name,this_player());
		name = creator(ob);
		report = "Object: "+ob->short()+" "+report;
		BUG_D->add_bug(name,path,report,this_player()->query_real_name(),ctime(time()));
		return;
	}
	
	if(present(name,environment(this_player()))) {
		
		
		ob = present(name,environment(this_player()));
		
		name = creator(ob);
		report = "Object: "+ob->short()+" "+report;
		BUG_D->add_bug(name,path,report,this_player()->query_real_name(),ctime(time()));
		return;
	}
	path = "none"
	BUG_D->add_bug(name,path,report,this_player()->query_real_name(),ctime(time()));
	return;
	
	
	
}