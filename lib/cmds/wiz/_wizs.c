status wussie(object ob) {
if(ob->query_wiz()) return 1;
return 0;
}

status sortting(object obj1, object obj2) {
  int i1,i2;
  i1=obj1->query_level();
  i2=obj2->query_level();
  return i1>i2;
}

cmd_wizs() {

object *ob;
int i;
int jouti;
string joutistr;


ob=users();
ob=filter(ob, "wussie");
ob=sort_array(ob, "sortting");
  write(
".--------------------------------------------------------.\n"+
"| Our fellow wizards online:                             |\n"+
"+--------------------------------------------------------+\n");

  for(i=sizeof(ob);i--; ) {
    joutistr="";
    jouti=query_idle(ob[i]);


if(jouti>=86400) {
	joutistr+=((jouti-(jouti%86400))/86400)+"d ";
	jouti=jouti%86400;
	}

if(jouti>=3600) {
	joutistr+=((jouti-(jouti%3600))/3600)+"h ";
	jouti=jouti%3600; 
	}



if(jouti>=60) {
	joutistr+=((jouti-(jouti%60))/60)+"m ";
	jouti=jouti%60;
}
    joutistr+=jouti+"s ";
    write(sprintf("|   %14-s %4|d %15s  %15s |\n",capitalize(ob[i]->query_real_name()),ob[i]->query_level(),query_ip_number(ob[i]),joutistr));
}

write("+--------------------------------------------------------+\n"+
      "| Time: "+ctime(time())[11..15]+"                                            |\n"+
      "+--------------------------------------------------------+\n");
return 1;
}
