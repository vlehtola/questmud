// Originally by Neophyte(?), fixes and enhancements by Nalle Dec '03

#include <ansi.h>

string *com;
string *edu;
string *net;
string *uk;
string *ca;
string *fi;
string *se;
string *us;
string *unknown;

cmd_countries(string str) {
	object ob;
	int i;
	string tmp;
	string result;
	result = "";
	ob = users();
			com = ({ });
			unknown = ({ });
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

} else unknown += ({ ob[i]->query_real_name(), }); }
write("Players are logged on from the following countries.\n");

result += make_country_string("Finland", fi); 
result += make_country_string("Commercial", com); 
result += make_country_string("Educational", edu); 
result += make_country_string("Network", net); 
result += make_country_string("United-Kingdom", uk); 
result += make_country_string("Canada", ca); 
result += make_country_string("Sweden", se); 
result += make_country_string("United States", us); 
result += make_country_string("Unknown", unknown);

result += "\n";
write(result);
return 1;
}

/********************************************************************/

string convert_to_namestrings(string *arr)
{
 int z;
 string temp;

 temp = "";

 for( z=0 ; z < sizeof(arr) ;z++) 
    {
     temp += capitalize(arr[z])+", ";
    }
 
 return temp[0..strlen(temp)-3];
}

/********************************************************************/

string make_country_string(string country, string* arr)
{
 string temp;
 
 if(!arr || !country || !sizeof(arr)) return "";

 if(this_player()->query_terminal())
    temp = sprintf("\n"+CYAN_F+"%-14s"+OFF, capitalize(country));
     else
    temp = sprintf("\n%-14s",capitalize(country));
    
 temp+= sprintf(" (%3d users,%3d%% of total)\n  ", sizeof(arr), sizeof(arr)*100/sizeof(users()) );

 if(this_player()->query_terminal())
  temp += BOLD+convert_to_namestrings(arr)+OFF;
   else
  temp += convert_to_namestrings(arr);

  temp += "\n";

 return temp;
}
