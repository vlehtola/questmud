inherit "room/room";

reset(arg) {
if(arg) return;

  move_object(clone_object("/wizards/kaappi/questplaque"), this_object());
  
  add_exit("inn", "/world/city/inn");
  add_exit("cs", "/world/city/cs");
  add_exit("mine", "mine/entrance");
  add_exit("dcity", "dcity/rooms/tunnele");
  add_exit("torni", "/wizards/nipa/areat/torni/huoneet/entrance");
  
  short_desc = "";
  long_desc="";
    
  property = allocate(1);
property[0] = "no_summon";

  set_light(3);
}

status is_wizard(object ob) {
if(ob->query_wiz()) return 1;
return 0;
}

status is_mortal(object ob) {
if(!ob->query_wiz()) return 1;
return 0;
}
 
status sort_by_name(object obj1, object obj2) {
int i1,i2;
i1=obj1->query_level();
i2=obj2->query_level();
return i1>i2;
}

long() {
object *ob;
int i;
int idletime;
string idles;
ob=users();
ob=filter_array(ob, "is_wizard");
ob=sort_array(ob, "sort_by_name");
write("Wizut:\n");
for(i=sizeof(ob);i--; ) {
string env2;
if(environment(ob[i])) { env2 = file_name(environment(ob[i])); }
else { env2 = ""; }
idles="";
idletime=query_idle(ob[i]);
if(idletime>=3600) {
  idles+=((idletime-(idletime%3600))/3600)+"h "; 
  idletime=idletime%3600;
}
if(idletime>=60) {
  idles+=((idletime-(idletime%60))/60)+"m ";
  idletime=idletime%60;
}
idles+=idletime+"s";

write(sprintf(" <%6|d> %10-s %28-s (%s) ", ob[i]->query_level(), capitalize(ob[i]->query_real_name()), env2, idles)+"\n");
}

/*MORTIT*/
 
write("Pellaajat:\n");

object *us;
int b;
int idlet;
string idlestring;
us=users();
us=filter_array(us, "is_mortal");
us=sort_array(us, "sort_by_name");
for(b=sizeof(us);b--; ) {
string env;
if(environment(us[b])) { env = file_name(environment(us[b])); }
else { env = ""; }
idlestring="";
idlet=query_idle(us[b]);
if(idlet>=3600) { 
  idlestring+=((idlet-(idlet%3600))/3600)+"h "; 
  idlet=idlet%3600;
}
if(idlet>=60) {
  idlestring+=((idlet-(idlet%60))/60)+"m ";
  idlet=idlet%60;
}
idlestring+=idlet+"s";

write(sprintf(" (%6|d) %10-s %28-s (%s) ", us[b]->query_level(), capitalize(us[b]->query_real_name()), env, idlestring)+"\n");
}
::long();
}
