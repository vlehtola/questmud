/* Added colours and separated the cases on 040602 - Nalle */

#include <ansi.h>

status is_npc(object ob);
status print_shape(string cap_monsu, int mob_hps, int stun_t);

cmd_scan(string monsu) {
    string cap_monsu;
    object ob;
    object *obs;
    int mob_hp;
    int i;
    int stun_t;
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
    stun_t = ob->query_stunned();
    // Print the shape
    print_shape(cap_monsu,mob_hp, stun_t);

 return 1;
}

/**************************************************************/

status is_npc(object ob){
    if(living(ob) && ob == this_player()->query_attack()) return 1;
    if(living(ob) && this_player() == ob->query_attacker()) return 1;

    return 0;
}

/**************************************************************/

status print_shape(string cap_monsu, int mob_hp, int stun_t) {
string start_c,end_c;
int colors_enabled;
string result;
// Only use the oclors if the term supports them
colors_enabled=this_player()->query_terminal();

// Init color strings
start_c=""; if(colors_enabled) end_c=OFF; else end_c="";

switch(mob_hp){
  case 0..13:
if(colors_enabled) start_c=BOLD;
result = cap_monsu + " is "+start_c+"about to die"+end_c+".";
break;
  case 14..20:
if(colors_enabled) start_c=RED_F;
result = cap_monsu + " is in "+start_c+"very bad shape"+end_c+".";
break;
  case 21..33:
if(colors_enabled) start_c=RED_F;
result = cap_monsu + " is in "+start_c+"bad shape"+end_c+".";
break;
case 34..50:
if(colors_enabled) start_c=YELLOW_F;
result = cap_monsu + " is "+start_c+"injured"+end_c+".";
break;
  case 51..75:
if(colors_enabled) start_c=YELLOW_F;
result = cap_monsu + " is "+start_c+"somewhat injured"+end_c+".";
break;
  case 76..80:
if(colors_enabled) start_c=GREEN_F;
result = cap_monsu + " is "+start_c+"slightly hurt"+end_c+".";
break;
  case 81..99:
if(colors_enabled) start_c=GREEN_F;
result = cap_monsu + " is in "+start_c+"good shape"+end_c+".";
break;
  default:
result = cap_monsu + " is in excellent shape.";
break;
}
if(stun_t) { result += " (Stunned)"; }
write(result+"\n");
return 1;
}

