cmd_pwho(string str) {
  object t, p_ob;
  object *members;
  string result;
  string *bguild;
  string mstatus;
  string pstatus;
  string rstatus;
  int i;
  if(!str) {
  write("pwho <player>\n");
  return 1;
}
t = find_player(lower_case(str));

if(!t || t->query_invisible()) {
	write("No such player online\n");
	return 1;
}

p_ob = t->query_party();
if(!p_ob) {
	write(capitalize(str)+" is not in a party.\n");
	return 1;
}
result = "";
members = p_ob->query_members();
members = m_indices(members);
result += sprintf("Party of (%-1s)\n", p_ob->query_party_name());
result += sprintf("+----------------------+-------+-------------+---------------------------+\n");
result += sprintf("| Name                 | Lvl   | Status      | Base-guild                |\n");
result += sprintf("+----------------------+-------+-------------+---------------------------+\n");
for(i=0;i<sizeof(members);i++) {
if(members[i]->query_name()) {
bguild = members[i]->query_starter_guild();
mstatus = "Alive";
pstatus = " (mbr)";
if(members[i]->query_ghost()) mstatus = "Ghost";
if(members[i]->query_link_dead()) mstatus = "Ld";
if(members[i] == p_ob->query_leader()) pstatus = " (ldr)";

if(p_ob->query_party_follow()[members[i]->query_name()]) pstatus = " (fol)";
if(!bguild) bguild = ({ "No-guild", "NoGuild", });
rstatus = mstatus+pstatus;
result += sprintf("| %-20s | %-5d | %-10s | %-25s |\n", members[i]->query_name(), members[i]->query_level(), rstatus, bguild[0]);
}
}
result += sprintf("+----------------------+-------+-------------+---------------------------+\n");
write(result);
return 1;
}
