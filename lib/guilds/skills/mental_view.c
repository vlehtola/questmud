#define MW_SP_NEEDED 50

get_time(str) {
  return random(2)+2;
}
ep_cost() { return 5; }
query_type() { return "neutral"; }


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

resolve_skill(str) {
    int att,def;
    object target;
object *obs;
string poks;
string temp;
string *exits;
int chance;
string exitit;
string enumb;
int i,a;
    
    if(!str && this_player()->query_attack()) {
      str = lower_case(this_player()->query_attack()->query_name());
    }
    if (!str) {
      write("Use mental view at whom?\n");
      return 1;
    }
        
    target = find_player(str);
    if(!target || !living(target)) {
      write(str+" is not a valid target.\n");
      return 1;
    }
    
    if(target->query_wiz()) {
    	write("You smartass!\n");
    	return 1;
}


    if(this_player()->query_sp() < MW_SP_NEEDED) {
    	
    	write("You lack the mental strength to accomplish this attack.\n");
    	return 1;
}
this_player()->reduce_sp(MW_SP_NEEDED);
    
    write("Suddenly you can see through "+capitalize(str)+"'s eyes\n");

obs = all_inventory(environment(target));
	poks = environment(target)->query_long();
	
	
	
	chance = this_player()->query_skills("mental view")/2;
	chance += this_player()->query_skills("knowledge of mind")/2;
	

if((chance + this_player()->query_level()) < target->query_level()) {
	write("You are not powerful enough to look through "+str+"'s eyes.\n");
	return 1;
}

		
	poks = sekota_stringi(poks,chance);	
	
	temp = "";
	exits = environment(target)->query_dest_dir();
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

}

fail_skill(str) {
    object target;
    if(!str) {
        write("Use mental view at who?\n");
        return 1;
    }
    if(random(100) < this_player()->query_skills("mental view")) {
        resolve_skill(str);
        return 1;
    }
    
    target = present(str, environment(this_player()));
    if (!target) { write("You fail the skill.\n"); return; }
    write("You lose your concentration and fail the skill.\n");
    
}