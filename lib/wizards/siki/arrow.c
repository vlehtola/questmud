string short_desc;
string long_desc;
int weight;
int damage;
int quality;
int hit_chance;
int crit_chance;
int stun_chance;
string maker;
string type;
string crafted;

query_missile_type() { return type; }
query_maker() { return maker; }
query_quality() { return quality; }
query_damage() { return damage; }
query_weight() { return 1; }
query_arrow() { return 1; }
query_name() { return short_desc; }
query_hit_chance() { return hit_chance; }
query_crit_chance() { return crit_chance; }
query_stun_chance() { return stun_chance; }


set_short(str) { short_desc=str; }
set_long(str) { long_desc=str; }
set_weight(i) { weight=i; }
set_damage(i) { damage=i; }
set_hit_chance(i) { hit_chance=i; }
set_crit_chance(i) { crit_chance=i; }
set_stun_chance(i) { stun_chance=i; }
set_maker(str) { maker=str; }
set_missile_type(str) { type=str; }

short() {
	return short_desc;
}
id(str) {
	return str == type;
}
long() {
	string tmp;
	tmp="";
	tmp+=short();
	tmp+="\n"+long_desc+"\n";
	tmp+="It is "+crafted+" crafted "+short_desc+".\n";
	tmp+="It was crafted by "+maker+".\n";
	write(tmp);
}
drop() { return 0; }
get() { return 1; }

set_quality(i) {
	quality = i;
	switch(i) {
	case 0..10:
	crafted="awfully";
	break;
	case 11..20:
	crafted="badly";
	break;
	case 21..30:
	crafted="basically";
	break;
	case 31..40:
	crafted="adequately";
	break;
	case 41..50:
	crafted="moderately";
	break;
	case 51..60:
	crafted="finely";
	break;
	case 61..70:
	crafted="flawlessly";
	break;
	case 71..80:
	crafted="superbly";
	break;
	case 81..90:
	crafted="perfectly";
	break;
	case 91..100:
	crafted="divinely";
	break;
}
}
