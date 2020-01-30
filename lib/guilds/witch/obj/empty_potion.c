#include "/guilds/witch/obj/potion_d.c"
#include "/guilds/witch/obj/drink.c"
#define THIS this_object()
string ldesc;
string label;
set_size(int bonus) {
if(bonus < 35) { size = 1; } else if(bonus > 65) { size = 3; }
else { size = 2; }
}
reset(arg) {
   if (arg) { return; }
   full = 0;
}
set_effect(int qua, string str) {
        full = 1;
        quality = qua;
        effect = str;
        prepared = 0;
        identified = 0;
        if(quality > 100)quality =100;

return 1;
}

do_pour() {
	full = 0;
	quality = 0;
	effect = 0;
	prepared = 0;
	identified = 0;
}

query_effect() { return effect; }

get_effect() {
        object ob;
        object siki;
        siki = find_player("siki");
        if(siki)tell_object(siki, this_player()->query_name()+ " Makes: "+effect+" vial and quality is: "+quality+"\n");
        ob = clone_object("/guilds/witch/potions/"+effect+".c");
        ob->start(quality, this_player());
        doze_left -= 1;
        if(query_doze_left() == 0) { full = 0; effect = "empty"; prepared = 0; identified = 0; }
        return 1;
}
get_lubricate(str) {
        object ob,tgt;
        tgt = str;
        ob = clone_object("/guilds/witch/potions/"+effect+".c");
        ob->start(quality, tgt);
        doze_left -= 1;
        if(query_doze_left() ==0) { full = 0; effect = "empty"; prepared = 0; identified = 0; }
        return 1;
}
set_prepared(int pre) {
        prepared = 1;
        max_doze = size;
        doze_left = size;
        return 1;
}
id(str) { return str == "vial" || str == label; }

get() { return 1; }

short() {
	string str;
	str = "";
	str += call_other("/guilds/witch/obj/potion_d", "get_short", effect);
	if(label)str += " named as '"+label+"'";
    return str;
}

query_potion() {
        return this_object();
}


long(str) {
        tell_object(this_player(),call_other("/guilds/witch/obj/potion_d", "get_short", effect)+".\n");
        tell_object(this_player(),"It is a "+call_other("/guilds/witch/obj/potion_d", "get_vial_size", size)+" sized and ");
        if(prepared==1) { tell_object(this_player(), "It is fully prepared.\n"); } else { tell_object(this_player(), "It is not prepared.\n"); }
        if(identified==1) { tell_object(this_player(), "It is a "+call_other("/guilds/witch/obj/potion_d", "get_identify", effect)+" vial.\n"); }
        if(identified==1) { tell_object(this_player(), "It has a "+doze_left+" doze left.\n");
        }
return 1;
}

query_long() {
	string ldesc;
	ldesc = call_other("/guilds/witch/obj/potion_d", "get_short", effect);
	ldesc += "\nIt is "+call_other("/guilds/witch/obj/potion_d", "get_vial_size", size)+" sized and ";
	if(prepared==1) { ldesc += "It is fully prepared.\n"; } else { ldesc += "It is not prepared.\n"; }
	if(identified==1) { ldesc += "It is "+call_other("/guilds/witch/obj/potion_d", "get_identify", effect)+" vial.\nIt has "+doze_left+" doze left\n."; }
	return ldesc;
	}

query_value() {
  return quality;
}

query_can_label() { return 1; }
set_label(string str) { label = str; }

query_weight() { if(prepared == 1) { return 200+quality; } else { return 100; } }

identify_vial() {
        identified = 1;
        if(!effect) { write("This is an empty vial.\n"); } else { write("it is "+call_other("/guilds/witch/obj/potion_d", "get_identify", effect)+" vial.\n"); }
        if(prepared==1) { write("It is a "+call_other("/guilds/witch/obj/potion_d", "get_quality", quality)+" quality.\n"); }
        if(prepared==1) { write("Tt has a "+doze_left+" doze left from "+max_doze+".\n"); } else  { write("It is not prepared.\n"); }
        return;
}
