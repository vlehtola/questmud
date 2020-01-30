object obj;
int c_str, size;
string hands;

int can_be_wielded(object ob, int st, int si, string hands) {
	object rw;
rw = this_player()->query_right_weapon();
if(ob->can_wield(st, si) == 0) return 0;
if(ob->query_weapon_type() == "shield" && this_player()->query_left_weapon()) return 0;
if(ob->query_weapon_type() == "bow" && this_player()->query_right_weapon()) return 0;
if(ob->query_weapon_type() == "bow" && this_player()->query_left_weapon()) return 0;
if(rw) {
if(ob->query_type() == "shield" && rw->query_slot() == "both hands") return 0;
if(ob->query_type() == "bow" && rw->query_slot() == "both hands") return 0;
if(hands == "left hand" && rw->query_slot() == "both hands") return 0;
}
if(hands == "both hands" && this_player()->query_right_weapon()) return 0;
if(hands == "both hands" && this_player()->query_left_weapon()) return 0;
if(hands == "right hand" && this_player()->query_right_weapon()) return 0;
if(hands == "left hand" && this_player()->query_left_weapon()) return 0;
return 1;
}

string wield_where(object ob, int st, int si, string hands) {
if(ob->query_weapon_type() == "shield") { return "left hand"; } else
if(ob->query_weapon_type() == "bow") { return "both hand"; } else
if(hands == "both hands") { return "both hands"; } else
if(hands == "right hand" && ob->can_wield(st, si) == 1) {return "right hand"; } else
if(hands == "left hand" && ob->can_wield(st, si) == 1) { return "left hand"; } else
if(ob->can_wield(st, si) == 2) { return "both hands"; } else
if(ob->can_wield(st, si) == 1) { return "right hand"; } else
if(ob->can_wield(st, si) == 1 && this_player()->query_right_weapon()) { return "left hand";
}
}

cmd_nwield(string str) {
    string what, tmp1, tmp2;
    if(!str) {
	write("Wield what?\n");
	return 1;
    }
    if(sscanf(str, "%s in %s %s", what, tmp1, tmp2) == 3) {
	obj = present(what, this_player());
	hands = tmp1+" "+tmp2;
    } else { obj = present(lower_case(str), this_player()); }
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
    if(!can_be_wielded(obj, size, c_str, hands)) { write("You can't wield that.\n"); return 1; }
    obj->set_slot(wield_where(obj, c_str, size, hands));
    this_player()->wield(obj);
return 1;
}