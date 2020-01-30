/* Banish daemon by Cendor */

#define SAVE_FILE "/data/banishes"

mapping names, sites;
int level, Wiza;

void reset() {
    names = ([ ]);
    sites = ([ ]);
    if(file_size(SAVE_FILE + ".o") > 0) {
      restore_object(SAVE_FILE); 
    }
}

mixed query_ban_name_time(string name) { return names[name,0]; }
mixed query_ban_site_time(string name) { return sites[name,0]; }

mixed query_name_banner(string name) { return names[name,1]; }
mixed query_site_banner(string name) { return sites[name,1]; }

string query_reason(string name) { return names[name, 3]; }
string query_sreason(string name) { return sites[name, 2]; }

mapping query_site_level(string name) { return sites[name,3]; }

int add_banish_name(string str, int atime, string reason) {
object ob;
object ob2;
string tmp;
int endtime;
    if(!reason) {
    write("You need reason to banish someone.\n");
    return 1;
}
    if(this_player()->query_wiz() < 3) {
    write("You are not allowed to banish.\n");
    return 1;
}

if(str && sscanf(str,"%s %s",str,tmp) != 2) {
    str = lower_case(str);
    ob = find_player(str);
    if(ob) ob->save_me(1);
    if(!restore_object("/players/"+str))    {
    write("No such character exists.\n");
    return 0;
}
    str = lower_case(str);
    if(names[ str ] && query_ban_name_time(lower_case(str)) > time()) {
    write("That name is already banished.\n");
    return 0;  
}
  
if(this_player()->query_level() <= level && this_player()->query_wiz() < 4) {
  write("You can't banish higher level wizards.\n");
  return 1;
} 
   if(atime) endtime = atime + time();
    names += (([ str:endtime;this_player()->query_real_name();this_player()->query_level();reason ]));
    save_object(SAVE_FILE);
    write(capitalize(str) + " has been banished because of '"+reason+"'.\n");
    log_file("BANISH", "NAME : "+ str +" was banished by "+ 
    this_player()->query_name()+", at time: "+ ctime(time()) +"\n"); 
    if(ob2 = find_living(str)) { 
      tell_object(ob2, "Suddenly a magical bolt strikes you and all goes dark.\n");
      ob2->save_me(1);
      destruct(ob2); 
    }
    "/room/banrecord_d"->add_record(str,this_player()->query_name(),reason,atime);
    return 1;
  }
}

int add_banish_site(string str,int atime,string reason) {
    if(this_player()->query_wiz() < 4) {
    write("You are not allowed to banish sites.\n");
    return 1;
}
    if(!reason) {
    write("You need reason to banish site.\n");
    return 1;
}
if(!str || !stringp(str) || str == "" ) return -1; 
    if(strlen(str) > 15) {
    write("That is not a valid IP.\n");
    return 1;
}
    if(sites[ str ]) {
    write("That site is already banished.\n");
    return 0;  }
    if(atime) atime = atime + time();
    sites += (([ str:atime;this_player()->query_real_name();reason ]));
    save_object(SAVE_FILE);
    write("Site : " + str + " has been banished because of '"+reason+"'\n");
    log_file("BANISH", "SITE : "+ str +" was banished by "+ 
    this_player()->query_name()+", at time: "+ ctime(time()) +"\n"); 
    return 1;
}


int check_banned_name(string name) {
    return ((member_array(name, m_indices(names)) != -1 ) ? 1 : 0 );
}


int check_banned_site(string ip) {
    int i, j, a1, a2, a3, a4, b1, b2, b3, b4;
 
    if (!sites)
        return 0;
    if (sscanf(ip, "%d.%d.%d.%d", a1, a2, a3, a4) != 4)
        return -1;                      
    for (i = 0; i < m_sizeof(sites); i++)
      { j = sscanf(m_indices(sites)[i], "%d.%d.%d.%d", b1, b2, b3, b4);
        if (a1 != b1)
            continue;
        if (j > 1 && a2 != b2)
            continue;
        if (j > 2 && a3 != b3)
            continue;
        if (j > 3 && a4 != b4)
            continue;
        return 1; }
    return 0;
}

int unbanish_name(string name) {
    if(!name || !stringp(name) || name == "") return -1;
    name = lower_case(name);
    
    if(member_array(name, m_indices(names)) == -1) {
    write("That name is not banished.\n");
    return 0;
}
    names -= ([ name ]);
    save_object(SAVE_FILE);
    log_file("BANISH", "NAME : "+ name +" was Unbanished by "+ 
    this_player()->query_name()+", at time: "+ ctime(time()) +"\n"); 
    write("Unbanished name : " + capitalize(name) + "\n");
    return 1;
}

int unbanish_site(string name) {
    if(!name || !stringp(name) || name == "" ) return -1;
    if(member_array(name, m_indices(sites)) == -1) {
    write("That site is not banished.\n");
    return 0;
}
    sites -= ([ name ]);
    save_object(SAVE_FILE);
    log_file("BANISH", "SITE : "+ name +" was Unbanished by "+ 
    this_player()->query_name()+", at time: "+ ctime(time()) +"\n"); 
    write("Unbanished site : " + name + "\n");
    return 1;
}

mixed *query_banished_names() { return m_indices(names); }

mixed *query_banished_sites() { return m_indices(sites); }
 
list_banished_names() {
  int i;
  string *temp;
  string *strr;
  strr = "";
  temp = query_banished_names();
  write(" Name         Banished by     Banish ends               Time left     \n");
  write("------------------------------------------------------------------------\n");
  for(i = 0; i < sizeof(temp); i++) { 
  if(query_ban_name_time(temp[i]) > time()) {
  strr  += " " + sprintf("%-11s", capitalize(temp[i]))+ "  ";  
  strr  += sprintf("%-16s", capitalize(query_name_banner(temp[i])));
  strr  += sprintf("%-26s", ctime(query_ban_name_time(temp[i]))); 
  strr  += sprintf("%-12s", time_left((query_ban_name_time(temp[i]) - time()))) + "  \n";
  }
} 
write(strr);
return 1;
}  
  

list_banished_sites() {
  int i;
  string *temp;
  string *strr;
  strr = "";
  temp = query_banished_sites();
  write(" Site              Banished by  Banish ends               Time left     \n");
  write("------------------------------------------------------------------------\n");
  for(i = 0; i < sizeof(temp); i++) { 
  if(query_ban_site_time(temp[i]) > time()) {
  strr  += " " + sprintf("%-16s",temp[i])+ "  ";  
  strr  += sprintf("%-13s", capitalize(query_site_banner(temp[i])));
  strr  += sprintf("%-26s", ctime(query_ban_site_time(temp[i]))); 
  strr  += sprintf("%-12s", time_left((query_ban_site_time(temp[i]) - time())))+ "\n";
  } 
}
write(strr);
return 1;
}

string time_left(int p) {  
  int i;
  string piu;
  
  piu = "";  
  i = p;  
  if(i/86400) {  
    piu += (i/86400) +"d ";  
    i = i - (i/86400)*86400;  
  }  
  if(i/3600) {  
    piu += (i/3600) +"h ";  
    i = i  - (i/3600)*3600;  
  }  
  if(i/60) {  
    piu += (i/60) +"m ";  
    i = i - (i/60)*60;   
  }  
  piu += i +"s";
  return piu;
}  


status info_name(string str) {
int a;
  if(!str || !names[str]) {
  write("That name is not banished!!!\n");
  return 1;
}
a = time();
str = lower_case(str);
write("Name        : " + capitalize(str) + ".\n");
write("Banished by : " + query_name_banner(str) + ".\n");
write("Reason      : " + query_reason(str) + ".\n");
write("Banish ends : " + ctime((int)query_ban_name_time(str)) + ".\n");
return 1;
}

status info_site(string str) {
int a;
  if(!str || !sites[str]) {
  write("That site is not banished!!!\n");
  return 1;
}
a = time();
str = lower_case(str);
write("Site         : " + capitalize(str) + ".\n");
write("Banished by  : " + query_site_banner(str) + ".\n");
write("Reason       : " + query_sreason(str) + ".\n");
write("Banish ends  : " + ctime((int)query_ban_site_time(str)) + ".\n");
return 1;
}


