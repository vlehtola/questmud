#define RACE_D "/daemons/race_stats"
#define SKILL_D "/guilds/obj/skillfun"

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
  add_action("cmd_halt", "halt");
  add_action("cmd_testguilds", "testgs");
  add_action("cmd_testskills", "testsk");
  add_action("cmd_nlist", "nlist");
}

cmd_nlist(str) {
	object ob;
	object pager;
	mixed *arr;
	string result;
	int i;
	if(!str) {
	write("Nlist <thing>\n");
	return 1;
}
ob = present(str,this_player());
if(!ob) {
	ob = present(str, environment(this_player()));
}
if(!ob) {
 ob = find_object(str);
}
if(!ob) {
ob = find_player(str);
}
if(!ob) {
	write("Flist: unable to find that object.\n");
	return 1;
}
arr = functionlist(ob);
result = "";
for(i=0;i<sizeof(arr);i++) {
	result += arr[i]+ "\n";
}
 pager = clone_object("/daemons/pager");
 pager -> move(this_object());
 pager ->page(result);
 return 1;
}
string_kuntoo(string skill) {
 string str1, str2, str3, str4;
 string rsk;
 rsk = skill;
 if (sscanf(skill, "%s_%s", str1, str2) == 2) { rsk = str1+" "+str2; }
 if (sscanf(skill, "%s_%s_%s", str1, str2, str3) == 3) { rsk = str1+" "+str2+" "+str3; }
 if (sscanf(skill, "%s_%s_%s_%s", str1, str2, str3, str4) == 4) { rsk = str1+" "+str2+" "+str3+" "+str4; }
 return rsk;
}

cmd_testskills() {
	string *files;
	string sk1, sk2;
	int i;
	string str;
	object pager;
	files = get_dir("/doc/skill/",1);
	str =  "+-----------------------------------------------------------------------+\n";
    str += "| Name                      | Type       | Ep  | Time | Cost            |\n";
   	str += "+-----------------------------------------------------------------------+\n";
	for(i=0;i<sizeof(files);i++) {
	if(file_size("/guilds/skills/"+files[i]+".c") != -1) {
    str += sprintf("| %-25s | %-10s | %-3d | %-4d | %-15s |\n",
    string_kuntoo(files[i]),
    call_other("/guilds/skills/"+files[i]+".c", "query_type"),
    call_other("/guilds/skills/"+files[i]+".c", "ep_cost"),
    call_other("/guilds/skills/"+files[i]+".c", "get_time"),
    SKILL_D->get_skill_cost_adjective(string_kuntoo(files[i])));
    } else { if(SKILL_D->get_skill_cost_adjective(string_kuntoo(files[i])) != "No skillcost defined") {
	str += sprintf("| %-25s | %-10s | %-3d | %-4d | %-15s |\n", string_kuntoo(files[i]),
	       "Automatic", 0, 0, SKILL_D->get_skill_cost_adjective(string_kuntoo(files[i])));
}
}
}
   	str += "+-----------------------------------------------------------------------+\n";
   	str += sprintf("| %-5d Skills |\n", sizeof(files));
   	str += "+--------------+\n";
   	pager = clone_object("/daemons/pager");
	pager->move(this_player());
	pager->page(str);
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

cmd_halt() {
	object *ob;
	int i;
	ob = all_inventory(environment(this_player()));
	for(i=0;i<sizeof(ob);i++) {
	if(ob[i]->query_attacker()) {
		ob[i]->stop_all();
		ob[i]->stop_fight();
		ob[i]->reset_hunger_list();
	}
}
	write("Halting combat.\n");
	say(this_player()->query_name()+" halts the combat.\n");
	return 1;
}
cmd_testguilds() {
string *files;
string *index;
mapping skills;
object pager;
string result, resulti;
int i, ii;
files = ({ "/guilds/abjurer/abjurers", "/guilds/abjurer/masters_of_abjuration.c", "/guilds/abjurer/masters_of_sorcery.c", "/guilds/abjurer/masters_of_vulnerability.c", "/guilds/channel/appr_cleric", "/guilds/channel/adept_cleric", "/guilds/channel/high_cleric", "/guilds/psi/psiguild", "/guilds/psi/fighter_psionicists", "/guilds/psi/caster_psionicists",
           "/guilds/necro/base_guild", "/guilds/necro/animators","/guilds/necro/control1","/guilds/necro/control2", "/guilds/necro/dark_power", "/guilds/necro/necro","/guilds/necro/unholy_lords",
           "/guilds/mage/adv_mages","/guilds/mage/apprmage","/guilds/mage/arcaners","/guilds/mage/electric_adept","/guilds/mage/fire_adept","/guilds/mage/ice_adept","/guilds/mage/illusionists","/guilds/mage/master_mage","/guilds/mage/merchant","/guilds/mage/navigator","/guilds/mage/scroll_scribblers",
           "/guilds/fighter/acrobats","/guilds/fighter/axes","/guilds/fighter/barbarian","/guilds/fighter/berserker","/guilds/fighter/blades","/guilds/fighter/bludgeons","/guilds/fighter/body_builders","/guilds/fighter/defender","/guilds/fighter/fighter","/guilds/fighter/ranger","/guilds/fighter/smith","/guilds/fighter/veterans","/guilds/fighter/warrior","/guilds/fighter/weapon_master",});
result = sprintf("Total of %-1d Guilds\n", sizeof(files));
for ( i = 0 ; i < sizeof(files); i++) {
	skills=files[i]->skill_list(files[i]->guild_max_level());
	if(skills)index=m_indices(skills);
	result += sprintf("\nGuild Name: %-25s\nGuild Max Lvl:%-5d\nGuild Stats:%10s\n",
	capitalize(files[i]->guild_name()),
	files[i]->guild_max_level(),
	files[i]->get_bonuses(files[i]->guild_max_level()));
result += sprintf("Guild Skills:\n");
	for(ii = 0 ; ii < sizeof(index); ii++) {
result += sprintf("%-25s %-2d%%\n", index[ii], skills[index[ii]]);
}
}
resulti=result;
pager = clone_object("/daemons/pager");
pager->move(this_player());
pager->page(resulti);
return 1;
}

short() {
  return "Siki's personal helping tool";
}
id(str) {
  return str == "tool";
}
long() {
  write("Commands available:\nwhere [arg]\nhalt\ntestgs\ntestqp\ntestsk\n");
}
drop() {
  return 1;
}
get() {
  return 1;
}
