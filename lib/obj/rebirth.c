/* player.c code:
mixed query_rebirth(string special) {
  if(!rebirth_time) return 0;
  if(rebirth_time && !rebirth_number) rebirth_number = 1;
  if(!special) return rebirth_number;
  return REBIRTH_OB->query_rebirth(special, this_object());
}
*/

// return values are percents
query_rebirth(string special, object player) {
  int n, level, chance;
  n = player->query_rebirth();
  level = player->query_level();
// modified by C 8.5.04
// chance stating from 2%, up to r3 l200 => 120*3/10 = 36%
// chance tuned. ++C 121010

  chance = level/4 + n *5;

  if(special == "avoid death") {
    if(chance > 25) chance = 25;
    if(chance > random(101)) return 1;
  }
  if(special == "absorb bolt") {
	if(chance > 48) chance = 48;
    	if(chance > random(101)) return 1;
  }
}

//Functions below by Rag, 2.1.2004

//Maximum number of rebirths, used by /obj/rebirth_room.c

// hardcoded the ugly way for ppl who are too persistant to play. C 261105
query_max_rebirth() { 

if (this_player()->query_name() == "Terror") return 3; // 19012009
if (this_player()->query_name() == "Alardolath") return 3;
if (this_player()->query_name() == "Elric") return 3;
if (this_player()->query_name() == "Reaper") return 3;
if (this_player()->query_name() == "Bloodstorm") return 3;
if (this_player()->query_name() == "Nightwish") return 3; // 31012008
if (this_player()->query_name() == "Ntg") return 3; // 26022008
if (this_player()->query_name() == "Golthar") return 3; // 14032008
if (this_player()->query_name() == "Laeh") return 3; //18032010
if (this_player()->query_name() == "Razarac") return 3; //29082010
if (this_player()->query_name() == "Olsma") return 3; //12102010
return 2; 
}

//Does the player have enough exp for rebirth
enough_exp(object player) {
        int *limits, rebirth_n, expneeded, exp;
        string expstr;
        
        //This much exp is needed for different rebirths (n*10^9)
        //limits = ({ 10, 20, 40, });  
	// I put the limits a bit higher, an idea from Celtron and Moonstar.
        // Old limits above. Retune if uproar or shit, but let us know. -N 041004
        limits = ({ 15, 30, 60, });
        
        rebirth_n = player->query_rebirth();
        expneeded = limits[rebirth_n];

        expstr = this_player()->query_total_string();
        
        //Just to make sure, exps should be checked before this function
        if(strlen(expstr) < 11) {
                write("Error, contact Rag!\n");
                return 0;
        }

        expstr = expstr[0..strlen(expstr)-10];
        exp = to_int(expstr);
        
        if(exp < expneeded) return 0;
        return 1;
}
