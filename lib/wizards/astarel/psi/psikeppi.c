reset(arg) {
  if(arg) return;
}

short() {
  return "The PSI-keppi";
}

id(str) {
  return str == "keppi";

}

long() {
  write("'psitest <target>'.\n"+
        "'psistun <target>'.\n"+
        "'psiconfuse <target>'\n"
        "'psirolli'\n");
}
get() {
	return 1;
}
query_weight() {
  return 1;
}

init() {

	add_action("psi_test","psitest");
	add_action("psistun","psistun");
	add_action("psiconfuse","psiconfuse");
	add_action("psidrain","psidrain");
	add_action("psirolli","psirolli");
	add_action("psicharm","psicharm");
	add_action("psiview","psiview");
	add_action("psiscan","psiscan");
	add_action("psibalance","psibalance");
	add_action("psiexpand","psiexpand");
	add_action("psiiwee","psiiwee");
}

status psiiwee() {

"wizards/astarel/psi/iron_will"->resolve_skill();

return 1;

}

status psiexpand() {

"wizards/astarel/psi/mental_expansion"->resolve_skill();

return 1;

}

status psibalance() {

"wizards/astarel/psi/mental_balance"->resolve_skill();

return 1;

}
string stringi_skilleille(int i,int sekotus) {
string temp;	
	if(!i)i=0;
	
	if(!random(2)) i += random(sekotus);
	else i -= random(sekotus);
		
	if(i<0)i = 0;
	if(i>100)i = 100;
	temp ="";
	
	switch(i) {
		case 0..4:    temp = "rotten";break;
		case 5..9:   temp = "feeble";break;
		case 10..14:   temp = "very poor";break;
		case 15..19:  temp = "poor";break;
		case 20..24: temp = "weak";break;
		case 25..29: temp = "lousy";break;
		case 30..34: temp = "low";break;
		case 35..39: temp = "quite low";break;
		case 40..44: temp = "adequate";break;
		case 45..49: temp = "average";break;
		case 50..54: temp = "mediocre";break;
		case 55..59: temp = "fair";break;
		case 60..64: temp = "nice";break;
		case 65..69: temp = "quite good";break;
		case 70..74: temp = "good";break;
		case 75..79: temp = "very good";break;
		case 80..84: temp = "great";break;
		case 85..89: temp = "marvelous";break;
		case 90..94: temp = "magnificent";break;
		case 95..99: temp = "superb";break;
		case 100: temp = "outstanding";break;
	}
	
return temp;
}
string stateille_stringi(int i,int sekotus) {
string temp;	
	if(!i)i = 0;
	
	if(!random(2)) i += random(sekotus);
	else i -= random(sekotus);
	
	if(i<0)i = 0;
	if(i>501)i = 501;
	temp ="";
	switch(i) {
		case 0..25:    temp = "rotten";break;
		case 26..50:   temp = "feeble";break;
		case 51..75:   temp = "very poor";break;
		case 76..100:  temp = "poor";break;
		case 101..125: temp = "weak";break;
		case 126..150: temp = "lousy";break;
		case 151..175: temp = "low";break;
		case 176..200: temp = "quite low";break;
		case 201..225: temp = "adequate";break;
		case 226..250: temp = "average";break;
		case 251..275: temp = "mediocre";break;
		case 276..300: temp = "fair";break;
		case 301..325: temp = "nice";break;
		case 326..350: temp = "quite good";break;
		case 351..375: temp = "good";break;
		case 376..400: temp = "very good";break;
		case 401..425: temp = "great";break;
		case 426..450: temp = "marvelous";break;
		case 451..475: temp = "magnificent";break;
		case 476..500: temp = "superb";break;
		case 501: temp = "outstanding";break;
	}
	
return temp;
}

status psiscan(string poks) {

object ob;
string result;
int i,j,sekotus,senssit;
mapping skills;
string *skillnames;
	if(!poks)return 1;
	if(!present(poks,environment(this_player())))return 1;
	ob = present(poks,environment(this_player()));
	if(!ob)return 1;
	if(!living(ob))return 1;

sekotus = 110;
sekotus -= this_player()->query_skills("mental scan")/2;
sekotus -= this_player()->query_skills("knowledge of mind")/2;
// sekotus min == 10;

senssit = this_player()->query_skills("mental scan")/2;
senssit = this_player()->query_skills("knowledge of mind")/2;

// senssit max == 100;

result = ".-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-.\n";
result +=sprintf("|  %67|s  |\n",ob->short());                             
result += "'-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-'\n";
result +=sprintf("|           Str: %11-s Dex: %11-s Con: %11-s          |\n",stateille_stringi(ob->query_str(),sekotus),stateille_stringi(ob->query_dex(),sekotus),stateille_stringi(ob->query_con(),sekotus));
result +=sprintf("|                    Wis: %11-s Int: %11-s                  |\n",stateille_stringi(ob->query_wis(),sekotus),stateille_stringi(ob->query_int(),sekotus) );
result += "'-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-'\n";
result += "| Skills:                Knowledge: | Skills:                Knowledge: |\n";
result += "'-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-'\n";

skills = ob->query_skills();
skillnames = m_indices(skills);

j = 1;

for(i=0;i<sizeof(skillnames);i++) {
	

result +=sprintf("| %21-s %11s |",capitalize(skillnames[i]),stringi_skilleille(skills[skillnames[i]],sekotus));
i++;
if(i<sizeof(skillnames))result += sprintf(" %21-s %11s |\n",capitalize(skillnames[i]),stringi_skilleille(skills[skillnames[i]],sekotus));
else result += "                                   |\n";
}

result +=       "'-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-'\n";
result +=       "|                                Resists:                               |\n";
result +=       "'-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-'\n";
result+=sprintf("| Physical:%11-s   Electric:%11-s  Asphyxiation:%11-s |\n",stringi_skilleille(ob->query_resists("physical"),sekotus),stringi_skilleille(ob->query_resists("electric"),sekotus),stringi_skilleille(ob->query_resists("asphyxiation"),sekotus));
result+=sprintf("| Psionic:%11-s        Poison:%11-s        Acid:%11-s |\n",stringi_skilleille(ob->query_resists("psionic"),sekotus),stringi_skilleille(ob->query_resists("poison"),sekotus),stringi_skilleille(ob->query_resists("acid"),sekotus));
result+=sprintf("|                Fire:%11-s         Cold:%11-s              |\n",stringi_skilleille(ob->query_resists("fire"),sekotus),stringi_skilleille(ob->query_resists("cold"),sekotus));
result +=       "'-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-'\n";
	   
tell_object(this_player(),result);

return 1;
}

string sekota_stringi(string str,int chance) {
int i,b,a;
string poks,temp;
string *jee;
string *kummamerkit;
	
kummamerkit = ({" ","%","#"});

poks = str;
temp = "";
a = chance;

	b = 0;
	for(i=0;i<strlen(poks);i++) {
	
	if(strlen(poks) > i)b += 1;
		
		if(jee =regexp(({poks[i..i]}),"[\n]"))
		if(sizeof(jee)) {
			temp += "\n";
			continue;
		
		}
		else if(a > random(100))temp += poks[i..i];
		else temp += kummamerkit[random(sizeof(kummamerkit))];
	
	}
return temp;
}


status psiview(string str) {
object ob;	
object *obs;
string poks;
string temp;
string *exits;
int chance;
string exitit;
string enumb;
int i,a;



	if(!str)return 1;
	if(!find_player(str) && !interactive(find_player(str)))return 1;
	
	ob = find_player(str);
	obs = all_inventory(environment(ob));
	poks = environment(ob)->query_long();
		
	chance = this_player()->query_skills("mental view")/2;
	chance += this_player()->query_skills("knowledge of mind")/2;
			
	poks = sekota_stringi(poks,chance);
		
	temp = "";
	exits = environment(ob)->query_dest_dir();
        exitit = "     There ";
        
        a = 1;
        for(i=0;i<sizeof(exits);i++){
                
                if(a != 1){
                if(a == (sizeof(exits)-1))temp += " and ";
                else if(a == (sizeof(exits))) temp += "";
                else temp += ", ";
                }
                temp+=exits[a];
                
                i++;
                
                a += 2;
                }
        i = sizeof(exits) / 2;
        switch(i) {
            case 0: enumb = "no";break;
            case 1: enumb = "one";break;
            case 2: enumb = "two";break;
            case 3: enumb = "three";break;
            case 4: enumb = "four";break;
            case 5: enumb = "five";break;
            case 6: enumb = "six";break;
            case 7: enumb = "eight";break;
            case 8: enumb = "nine";break;
            case 10: enumb = "ten";break;
            case 11: enumb = "eleven";break;
            case 12: enumb = "twelve";break;
            case 13: enumb = "thirteen";break;
            case 14: enumb = "fourteen";break;
            case 15: enumb = "fifteen";break;
            case 16: enumb = "sixteen";break;
            case 17: enumb = "seventeen";break;
            case 18: enumb = "eighteen";break;
            case 19: enumb = "nineteen";break;
            case 20: enumb = "twenty";break;
            default: "too many";break;
        }
	if(i<=1)exitit += "is ";
	else exitit += "are ";
	exitit += enumb+" ";
	exitit += "obvious exit";
	if(i<=1) exitit += ": ";
	else exitit += "s: ";
	exitit += temp;
	exitit += "\n";
	
	exitit = sekota_stringi(exitit,chance);
	poks += exitit;
        
        temp = "";
        
        for(i=0;i<sizeof(obs);i++) {
        	if(chance > random(100))temp += obs[i]->short()+"\n";
        	
        }
       
       temp = sekota_stringi(temp,chance);
       poks += temp;        
       	
	tell_object(this_player(),poks);
	
	return 1;
}

status psicharm(string str) {

if(!str)return 1;	
"wizards/astarel/psi/charm"->resolve_skill(str);

return 1;

}

status psirolli() {
	
	move_object(clone_object("/wizards/astarel/psi/mosa.c"),environment(this_player() ) );
	return 1;
}


status psidrain(string str) {

	if(!str)return 1;	
	"wizards/astarel/psi/mental_drain"->resolve_skill(str);
	return 1;
}

status psiconfuse(string str) {

	if(!str)return 1;	
	"wizards/astarel/psi/confuse"->resolve_skill(str);
	return 1;
}

status psistun(string str) {

	if(!str)return 1;	
	"wizards/astarel/psi/shake_mind"->resolve_skill(str);
	return 1;
}


status psi_test(string str) {
object ob;	
	if(!str)return 1;
	if(!present(str,environment(this_player())))return 1;
	ob = present(str,environment(this_player()));
	if(!ob)return 1;
	"/wizards/astarel/psi/psicombat"->attack(this_player(),ob);
return 1;

}
