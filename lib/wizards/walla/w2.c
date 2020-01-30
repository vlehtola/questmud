inherit "room/room";
 
object hani,hani2,hani3;
 
reset(arg) {
  if(!hani) {
    hani = clone_object("/world/objects/trashcan");
    move_object(hani, this_object()); }
  if(!hani2) {
    hani2 = clone_object("/world/objects/fountain");
    move_object(hani2, this_object()); }
  if(!hani3) {
    hani3 = clone_object("/wizards/walla/viivi");
    move_object(hani3, this_object()); }
  if(arg) return;
  property = ({ "no_summon", });
  add_exit("nalle","wizards/nalle/workroom");
  add_exit("east","wizards/walla/workroom");
  add_exit("inn","world/city/inn");
  add_exit("reinc","world/special/free_reinc_room");
  add_exit("events","wizards/siki/event_room");
  add_exit("post","world/city/post");
  add_exit("cs","world/city/cs");
  add_exit("rag","wizards/rag/workroom");
  add_exit("jenny","wizards/jenny/workroom");
  add_exit("devil","wizards/devil/workroom");
  short_desc = "Walla's livingroom";
  long_desc =
"Walla's chillout lounge.\n" +
"Nothing much to see here.\n" +
"misuja on joka kulmassa, ja nakojaan jaakaappi taynna\n" +
"kaljaa on tuolla. Suihkulahdeki on olemassa\n" +
"Muut voiki sitte lahtee pois taalta.\n";
}
  
status is_wizard(object ob) {
  if(ob->query_wiz()) return 1;
  return 0;
}
 
status sort_by_name(object o1, object o2) {
  int s1,s2;
  s1=(int)o1->query_level();
  s2=(int)o2->query_level();
  return s1<s2;
}
 
long() {
  object *ob;
  int i;
  int idletime;
  string idlestring;
  ob=users();
  ob=filter_array(ob, "is_wizard");
  ob=sort_array(ob, "sort_by_name");
    write("Wizards currently logged on:\n");
    for(i=sizeof(ob);i--; ) {
      idlestring="";
      idletime=query_idle(ob[i]);
      if(idletime>=86400) {
        idlestring+=((idletime-(idletime%86400))/86400)+"d ";
        idletime=idletime%86400;
      }
      if(idletime>=3600) {
        idlestring+=((idletime-(idletime%3600))/3600)+"h ";
        idletime=idletime%3600;
      }
      if(idletime>=60) {
        idlestring+=((idletime-(idletime%60))/60)+"m ";
        idletime=idletime%60;
      }
      idlestring+=idletime+"s ";
 
      write(sprintf("   <%6|d>  %10-s   (idle: %s) ",
  ob[i]->query_level(),
  capitalize(ob[i]->query_real_name()), idlestring)+"\n");
    }
 
write("Current time is: "+ctime(time())[11..15]+"\n");
    ::long();
}
