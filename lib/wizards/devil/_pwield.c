object obj;
int c_str, size;
string hands;

int can_be_wielded(object ob, int st, int si, string hands) {
object rw,lw;
lw = this_player()->query_left_weapon();
rw = this_player()->query_right_weapon();

if(ob->can_wield(st, si) == 0) return 0;
if((ob->can_wield(st, si) == 1) && (rw && lw)) return 0;
if((ob->can_wield(st, si) == 2) && (rw || lw)) return 0;

if(rw) if((rw->query_forced2h()) && (rw || lw)) return 0;
if(lw) if((lw->query_forced2h()) && (rw || lw)) return 0;

if(lw) if(lw->query_weapon_type() == "bow") return 0;
if(rw) if(rw->query_weapon_type() == "bow") return 0;

if(hands=="both hands" && (lw || rw)) return 0; // forced 2h wield
 
if(rw && lw) return 0; // Change if +2h creatures added

if(ob->query_weapon_type() == "shield" && lw) return 0;
if(ob->query_weapon_type() == "bow" && (rw || lw)) return 0;

return 1;
}

string wield_where(object ob, int st, int si, string hands) {
object rw,lw;
lw = this_player()->query_left_weapon();
rw = this_player()->query_right_weapon();
   
if(ob->query_weapon_type() == "shield") return "left hand"; 
if(ob->query_weapon_type() == "bow") return "both hands"; 
if(ob->can_wield(st, si) == 2) return "both hands";

if(hands=="both hands") { // for forced 2h wield
 if((ob->can_wield(st, si) == 1) && (ob->query_weapon_type() != "bow")) 
                                {
 write("Forced 2h bonuses enabled.\n");
 ob->enable_forced2h();
                                }
 return "both hands";
                        }

if((ob->can_wield(st, si) == 1) && rw && (!lw)) return "left hand"; 
if((ob->can_wield(st, si) == 1) && (!rw) && lw) return "right hand"; 
if((ob->can_wield(st, si) == 1) && (!rw) && (!lw)) return "right hand"; 

if(ob->can_wield(st, si) == 2) write("Wield error.\n");
}

cmd_pwield(string str) {
    string what, tmp1, tmp2;
    if(!str) {
        write("Wield what?\n");
        return 1;
    }
    if(sscanf(str, "%s in %s %s", what, tmp1, tmp2) == 3) {
        obj = present(what, this_player());
        hands = tmp1+" "+tmp2;
 if(hands!="both hands")        { 
 write("Weapons for one hand are automatically assigned.\n"); 
 return 1;
                                }
    } else 
    { obj = present(lower_case(str), this_player()); hands="";}

    if (!obj) {
        write("Wield what?\n");
        return 1;
    }
    if (!obj->query_weapon()) { write("You can't wield that.\n"); return 1; }
    if (obj->query_wielded()) {
        write("You are already wielding "+obj->short()+"!\n");
        return 1;
    }
    c_str = this_player()->query_str();
    size = this_player()->query_size();

    if(!can_be_wielded(obj, size, c_str, hands)) 
    { write("You can't wield that.\n"); return 1; }

    obj->set_slot(wield_where(obj, c_str, size, hands));
    this_player()->wield(obj);
return 1;
}
