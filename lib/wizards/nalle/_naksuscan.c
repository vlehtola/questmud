/* Added colours and separated the cases on 040602 - Nalle */

#include <ansi.h>

status is_npc(object ob);
status print_shape(string cap_monsu, int mob_hps);

cmd_naksuscan(string monsu) {
    string cap_monsu;
    object ob;
    object *obs;
    int mob_hp;
    int i;
    if (!this_player()->check_condis()) { return 1; }
    if (!this_player()->query_attack() && !monsu) {
        write("You are not in combat right now.\n");
        return 1;
    }
    if (!monsu && this_player()->query_attack()) 
                                  { ob = this_player()->query_attack(); }
    if(monsu == "all") {
        obs = all_inventory(environment(this_player()));
        obs = filter_array(obs,"is_npc");
        if(sizeof(obs)==0){
                write("None of your enemies are here.\n");
                return 1;
        }
        for(i=0;i<sizeof(obs);i++) {
        cap_monsu = capitalize(obs[i]->query_name());
        mob_hp = obs[i]->query_hp()*100 / obs[i]->query_max_hp();

        // Prints the shape
        print_shape(cap_monsu,mob_hp);                        
 }
return 1;       
}
    if (!ob&&monsu) { ob = present(monsu, environment(this_player())); }
        
    if (!ob) {
        write("No " + monsu + " here.\n");
        return 1;
    }
    if(!living(ob) || !ob->query_max_hp()) {
        write(monsu+" is not a living thing.\n");
        return 1;
    }
    cap_monsu = capitalize(ob->query_name());
    if(ob->query_gender())
        cap_monsu = capitalize(ob->query_pronoun());
    
    
    mob_hp = ob->query_hp()*100 / ob->query_max_hp();

    // Print the shape
    print_shape(cap_monsu,mob_hp);                        
        
 return 1;
}

/**************************************************************/

status is_npc(object ob){
    if(living(ob) && ob == this_player()->query_attack()) return 1;
    if(living(ob) && this_player() == ob->query_attacker()) return 1;
     
    return 0;
}

/**************************************************************/

status print_shape(string cap_monsu, int mob_hp) {
string start_c,end_c;
int colors_enabled;

// Only use the oclors if the term supports them
colors_enabled=this_player()->query_terminal(); 

// Init color strings
start_c=""; if(colors_enabled) end_c=OFF; else end_c="";

switch(mob_hp){
  case 0..13:
start_c=BOLD+RED_F;
write(cap_monsu + " is "+start_c+"about to die"+end_c+".\n"); 
break;
  case 14..20:
start_c=RED_F;
write(cap_monsu + " is in "+start_c+"very bad shape"+end_c+".\n");
 break;
  case 21..33:
start_c=YELLOW_F;
write(cap_monsu + " is in "+start_c+"bad shape"+end_c+".\n"); 
break;
  case 34..50:
start_c=YELLOW_F;
write(cap_monsu + " is "+start_c+"injured"+end_c+".\n"); 
break;
  case 51..75:
start_c=YELLOW_F;
write(cap_monsu + " is "+start_c+"somewhat injured"+end_c+".\n"); 
break;
  case 76..80:
start_c=GREEN_F;
write(cap_monsu + " is "+start_c+"slightly hurt"+end_c+".\n"); 
break;
  case 81..99:
start_c=GREEN_F;
write(cap_monsu + " is in "+start_c+"good shape"+end_c+".\n"); 
break;
  default:
start_c=WHITE_F;
write(cap_monsu + " is in "+start_c+"excellent shape"+end_c+".\n"); 
break;            
           }
return 1;
} 

