string *com;
string *edu;
string *net;
string *uk;
string *ca;
string *fi;
string *se;
string *us;
string *unknow;
cmd_countries(string str) {
	object ob;
	int i;
	string tmp;
	string result;
	result = "";
	ob = users();
			com = ({ });
			unknow = ({ });
			edu = ({ });
			net = ({ });
			uk = ({ });
			ca = ({ });
			fi = ({ });
			se = ({ });
			us = ({ });
	for(i=0;i<sizeof(ob);i++) {
	if(sscanf(query_ip_name(ob[i]), "%s.fi", tmp)) {
	fi += ({ ob[i]->query_real_name(), });
	tmp = "";
} else if(sscanf(query_ip_name(ob[i]), "%s.com", tmp)) {
	tmp = "";
	com += ({ ob[i]->query_real_name(), });
} else if(sscanf(query_ip_name(ob[i]), "%s.edu", tmp)) {
	edu += ({ ob[i]->query_real_name(), });
		tmp = "";
} else if(sscanf(query_ip_name(ob[i]), "%s.net", tmp)) {
	net += ({ ob[i]->query_real_name(), });
		tmp = "";

} else if(sscanf(query_ip_name(ob[i]), "%s.uk", tmp)) {
	uk += ({ ob[i]->query_real_name(), });
		tmp = "";

} else if(sscanf(query_ip_name(ob[i]), "%s.ca", tmp)) {
	ca += ({ ob[i]->query_real_name(), });
		tmp = "";

} else if(sscanf(query_ip_name(ob[i]), "%s.se", tmp)) {
	se += ({ ob[i]->query_real_name(), });
		tmp = "";
} else if(sscanf(query_ip_name(ob[i]), "%s.us", tmp)) {
	us += ({ ob[i]->query_real_name(), });
		tmp = "";

} else unknow += ({ ob[i]->query_real_name(), }); }
write("Players are logged on from the following countries.\n");
if(sizeof(fi)>0)result += "\nFinland("+sizeof(fi)+") : ";
for(i=0;i<sizeof(fi);i++) {
if(fi[i])
result += fi[i]+", ";
}
if(sizeof(com)>0)result += "\nCommercial("+sizeof(com)+") : ";
for(i=0;i<sizeof(com);i++) {
if(com[i])result += com[i]+", ";
}
if(sizeof(edu)>0)result += "\nEducational("+sizeof(edu)+") : ";
for(i=0;i<sizeof(edu);i++) {
if(edu[i])result += edu[i]+", ";
}
if(sizeof(net)>0)result += "\nNetwork("+sizeof(net)+") : ";
for(i=0;i<sizeof(net);i++) {
if(net[i])result += net[i]+", ";
}
if(sizeof(uk)>0)result += "\nUnited-kingdom("+sizeof(uk)+") : ";
for(i=0;i<sizeof(uk);i++) {
if(uk[i])result += uk[i]+", ";
}
if(sizeof(ca)>0)result += "\nCanada("+sizeof(ca)+") : ";
for(i=0;i<sizeof(ca);i++) {
if(ca[i])result += ca[i]+", ";
}
if(sizeof(se)>0)result += "\nSweden("+sizeof(se)+") : ";
for(i=0;i<sizeof(se);i++) {
if(se[i])result += se[i]+", ";
}
if(sizeof(us)>0)result += "\nUnited State:("+sizeof(us)+") : ";
for(i=0;i<sizeof(us);i++) {
if(us[i])result += us[i]+", ";
}
if(sizeof(unknow)>0)result += "\nUnknow("+sizeof(unknow)+") : ";
for(i=0;i<sizeof(unknow);i++) {
result += unknow[i]+", ";
}
result += "\n";
write(result);
return 1;
}