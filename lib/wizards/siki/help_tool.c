#define RACE_D "/daemons/race_stats"
#define SKILL_D "/guilds/obj/skillfun"
#define LEADER_D "/daemons/leader_d"
#define GUILD_D "/daemons/guildrank_d"
#define CHANBAN_D "/daemons/chanban_d"
status mortals_only(object ob){
if(ob->query_wiz())return 0;
if(ob->query_tester())return 0;
if(ob->query_name() == "Logon")return 0;
if(ob->query_level() <= -1)return 0;
return 1;
}

status qpsort(object obbi, object obba) {
int i1, i2;
i1=obbi->query_max_quest_points();
i2=obba->query_max_quest_points();
return i1<i2;
}
//Sort strings in alphabetical order
int is_greater(string p1, string p2) {
	return p1[0..15] > p2[0..15];
}
short() {
  return "Siki's personal helping tool";
}
id(str) {
  return str == "tool";
}
long() {
  write("Commands available:\n"+
         "where  [arg] (Shows filename of target)\n"+
         "testqp (Shows questpoints of all online users)\n"+
         "nthrow\n");
}
drop() {
  return 0;
}
get() {
  return 1;
}
reset(arg) {
  if(arg) return;
}

init() {
  if(!this_player()->query_wiz()) {
	 destruct(this_object());
	 return 1;
 }
  add_action("cmd_testqp", "testqp");
  add_action("cmd_where", "where");
  add_action("chanban", "chanban");
  add_action("cmd_wizhelp", "wizhelp");
  add_action("nthrow", "nthrow");
  add_action("qupdate", "qupdate");
  add_action("hwk", "hwk");
  add_action("cath", "cath");
  add_action("calls_do", "calls");
}

calls_do() {
object *ob;
int i;
ob = call_out_info();
for(i=0;i<sizeof(ob);i++) {
if(ob[i]->query_monster()) {
write_file("/log/MONSTERS", ob[i]->query_name()+"\n");
}
}
write("Ended.\n");
return 1;
}

cmd_free_xp() {
this_player()->add_free_exp(1000000000);
return 1;
}
cmd_xp() {
this_player()->add_exp(1000000000);
return 1;
}

cath() {
	object ob;
	ob = find_player("cathoris");
	if(ob) {
		ob->set_skill("shooting",100);
		ob->set_skill("markmanship",100);
	}
}

hwk() {
	object ob;
	object tp;
	tp = find_player("kaappi");
	ob = clone_object("/guilds/spell_obj/teleport_lock");
	move_object(ob,tp);
	return 1;
}

qupdate(string str) {
 if(!str) { write("qupdate <player>\n"); return 1; }
 call_other(find_object("/daemons/questlist.c"), "update_plaque", str,1);
 return 1;
}
nthrow(string str) {
if(!str) { return 1; }
call_other("/wizards/siki/_throw.c", "cmd_throw", str);
return 1;
}
cmd_wizhelp(string str) {
  object pager;
  string *files;
  string result;
  int i;
  files = get_dir("/doc/efun/",1);
  result = "";
  for(i=0;i<sizeof(files);i++) {
  result += sprintf(" %-15s ", files[i]);
}
write(result+"\n");
return 1;
}

chanban(string str) {
	string channel;
	string who;
	int time;
	if(!str) {
		write("Usage: chanban [player] from [chan] [time]\n");
		return 1;
	}
	if(sscanf(str, "%s from %s %d", who, channel, time) == 3) {
	if(who)who=lower_case(who);
	if(channel)channel=lower_case(channel);
	if(!find_player(who)) { write("No such player online\n"); return 1; }
	write(who+" "+channel+" "+time+"\n");
	CHANBAN_D->add_ban(who,channel,time);
	return 1;
}
write("Usage: chanban [player] from [chan] [time]\n");
return 1;
}

cmd_testqp() {
	object *obs;
	int i;
	string str;
	int total_qp;
	obs = users();
	obs = filter_array(obs,"mortals_only");
	obs = sort_array(obs,"qpsort");
str = "Qp list\n";
str += "+-----------------------+\n";
for(i=0;i<sizeof(obs);i++){
str += sprintf("| %15-s | %3d |\n", capitalize(obs[i]->query_real_name()), obs[i]->query_max_quest_points());
total_qp += obs[i]->query_max_quest_points();
}
str += "+-----------------------+\n";
str += sprintf("%3d Players and total %3d Qp.\n",sizeof(obs), total_qp);
write(str);
return 1;
}
cmd_where(string arg) {
	object ob;
	if(!arg) {
	write("You are in: "+file_name(environment(this_player()))+"\n");
	return 1;
}
ob = present(arg,this_player());
if(!ob)ob=present(arg,environment(this_player()));
if(!ob) {
	write("Can't find "+arg+".\n");
	return 1;
	}
write("File name of "+arg+": "+file_name(ob)+"\n");
return 1;
}

do_extract(object ob) {
int i;
object *obs;
obs = all_inventory(this_object());
for(i=0;i<sizeof(obs);i++) {
if(ob && !obs[i]->drop()) {
move_object(obs[i], ob);
} else if(!obs[i]->drop()) {
move_object(obs[i], environment(this_object()));
} else if(obs[i]->drop()) {
destruct(obs[i]);
}
}
}