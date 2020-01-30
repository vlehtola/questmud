get_time() {
	return 5;
}

ep_cost() { return 10; }

query_type() { return "neutral"; }

string stringi_skilleille(int i) {
string temp;
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
string stateille_stringi(int i) {
string temp;
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

resolve_skill(str) {

object ob;
string result;
int i,j,senssit;
mapping skills;
string *skillnames;


	if(!str) {
	write("Use consider demon at who?\n");
	return 1;
	}
	ob = present(str,environment(this_player()));
	if(!ob) {
	write("No "+str+" here.\n");
	return 1;
	}
	if(!living(ob)) {
	write("That aint living!\n");
	return 1;
	}

	if(!ob->query_demon()) {
	write("You can only consider demons with this skill.\n");
	return 1;
	}
result = ".-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-.\n";
result +=sprintf("|  %67|s  |\n",ob->short());
result += "'-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-'\n";
result +=sprintf("|           Str: %11-s Dex: %11-s Con: %11-s          |\n",stateille_stringi(ob->query_str()),stateille_stringi(ob->query_dex()),stateille_stringi(ob->query_con()));
result +=sprintf("|                    Wis: %11-s Int: %11-s                  |\n",stateille_stringi(ob->query_wis()),stateille_stringi(ob->query_int()) );
result += "'-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-'\n";
result += "| Skills:                Knowledge: | Skills:                Knowledge: |\n";
result += "'-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-'\n";

skills = ob->query_skills();
if(skills)skillnames = m_indices(skills);
j = 1;
for(i=0;i<sizeof(skillnames);i++) {
if(skills)
result +=sprintf("| %21-s %11s |",capitalize(skillnames[i]),stringi_skilleille(skills[skillnames[i]]));
i++;
if(i<sizeof(skillnames))result += sprintf(" %21-s %11s |\n",capitalize(skillnames[i]),stringi_skilleille(skills[skillnames[i]]));
else result += "                                   |\n";
}

result +=       "'-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-'\n";
result +=       "|                                Resists:                               |\n";
result +=       "'-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-'\n";
result+=sprintf("| Physical:%11-s   Electric:%11-s  Asphyxiation:%11-s |\n",stringi_skilleille(ob->query_resists("physical")),stringi_skilleille(ob->query_resists("electric")),stringi_skilleille(ob->query_resists("asphyxiation")));
result+=sprintf("| Psionic:%11-s        Poison:%11-s        Acid:%11-s |\n",stringi_skilleille(ob->query_resists("psionic")),stringi_skilleille(ob->query_resists("poison")),stringi_skilleille(ob->query_resists("acid")));
result+=sprintf("|                Fire:%11-s         Cold:%11-s              |\n",stringi_skilleille(ob->query_resists("fire")),stringi_skilleille(ob->query_resists("cold")));
result +=       "'-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-'\n";

tell_object(this_player(),result);

return 1;
}

fail_skill(str) {
	write("You fail the skill.\n");
	say(this_player()->query_name()+" fails the skill.\n");
}