string aname, dname, s, apos, dpos;
object attacker_ob;
int is_light;
string weapon_type;

write_combat_texts(object attacker, int i, object name_of_weapon) {
  weapon_type = "bare hands";
  if (name_of_weapon) { weapon_type = name_of_weapon->query_type(); }
  if(!name_of_weapon && attacker->query_npc()) weapon_type = "bludgeon";
  if (attacker->query_animal()) { weapon_type = "animal"; }
  s1 = ""; s2 = ""; aname = "You"; apos = "your";
  dpos = attacker_ob->query_possessive(); dname = attacker_ob->query_name();
  tell_object(attacker, aname+" "+get_text(i, weapon_type));
  s = "s"; s2 = "es"; aname = attacker->query_name(); apos = attacker->query_possessive();
}

get_text(int i, string wt) {
  if(i == 0) return "hit"+s+" "+dname+", but "+apos+" blow bounces off from "+dpos+" armour.\n";
  if(wt == "bare hands") {
    switch(i) {
case 1..2: return "weakly pat"+s+" "+dname;
case 3..5: return "pat"+s+" "+dname;
case 6..10: return "bump"+s+" "+dname;
case 11..17: return "smack"+s+" "+dname;
case 18..30: return "deliver"+s+" a nasty punch on "+dname;
case 31..50: return "swing"+s+" "+apos+" fist and hit"+s+" "+dname;
    }
    return "roar"+s+" mightily and punch"+s+" "+dname+" with a crushing force.";
  }
  if(wt == "bludgeon") {
    switch(i) {
case 1..5: return "weakly bump"+s+" "+dname;
case 6..10: return "bump"+s+" "+dname;
case 11..15: return "pummel"+s+" "+dname;
case 16..30: return "bash"+s2+" "+dname;
case 31..50: return "pound"+s+" "+dname;
case 51..80: return "quickly turns around "+apos+" heel and smash"+s2+" "+dname;
case 81..130: return "brutally hammer"+s+" "+dname+" with amazing force";
case 131..250: return "step"+s+" forward and aim"+s+" a devastating blow on "+dname;
    }
    return "jees";
  }
  if (weapon_type == "axe") {
    switch(i) {
case 1..5: return "weakly scratch"+s2+";
    }
  }
}
        if (tmp < 6) {
             how = "weakly scratch";
             how2 = "weakly scratches";
        }
        if (tmp > 5) {
             how = "barely hit";
             how2 = "barely hits";
        }
        if (tmp > 15) {
             how = "weakly hit";
             how2 = "weakly hits";
        }
        if (tmp > 40) {
             how = "swing and hit";
             how2 = "swings and hits";
        }
        if (tmp > 80) {
             how = "whack";
             how2 = "whacks";
        }
        if (tmp > 140) {
             how = "hack";
             how2 = "hacks";

