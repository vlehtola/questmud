status mortut(object ob){
if(ob->query_wiz())return 0;
if(ob->query_tester())return 0;
if(ob->query_name() == "Logon")return 0;
if(ob->query_level() <= -1)return 0;
return 1;
}
status sorttaus(object obbi, object obba) {
int i1, i2;
i1=obbi->query_level();
i2=obba->query_level();
return i1<i2;
}

string expat_sillai_hienosti(object ob) {

	int i,a;
	string stemp,stemp2;


	stemp = ob->query_total_string();

	if(strlen(stemp) <= 6) return "Below 1 Meg";
	stemp2 = "";
	a = strlen(stemp);
	a -= 6;
	for(i=0;i<a;i++) {

		stemp2 += stemp[i..i];
		

	}



a = to_int(stemp2);

if(a>=1000) {
	stemp = ((a-(a%1000))/1000)+"G ";
	a=a%1000;
	stemp += a+"Megs";
}
else stemp = a+"Megs";

return stemp;

}

cmd_mstats(){
int i;
object *us;
string str;

us = users();
us = filter_array(us,"mortut");
us = sort_array(us,"sorttaus");
str = ".---------------------------------------------------------------------------.\n";
str+= "| name:      | lvl | str | dex | con | int | wis | siz | XpR |  Totalworth  |\n";
str+= "+------------+-----+-----+-----+-----+-----+-----+-----+-----+--------------+\n";

for(i=0;i<sizeof(us);i++){

str += sprintf("| %10-s | %3|d | %3|d | %3|d | %3|d | %3|d | %3|d | %3|d | %3|d | %12s |\n",
               capitalize(us[i]->query_real_name()),
               us[i]->query_level(),
               us[i]->query_str(),
               us[i]->query_dex(),
               us[i]->query_con(),
               us[i]->query_int(),
               us[i]->query_wis(),
               us[i]->query_size(),
               us[i]->query_exp_rate(),
               expat_sillai_hienosti(us[i])
               );
          } 
str +="+------------+-----+-----+-----+-----+-----+-----+-----+-----+--------------+\n";
str += sprintf("| %3d Mortals online.                                                       |\n",sizeof(us));
str +="+---------------------------------------------------------------------------+\n";
write(str);          
return 1;
        }
