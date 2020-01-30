inherit "obj/weapon";
int warlock_boost;

start() {
  set_class(1);
  set_sub_type("dagger");
  set_short("A chaos sword (Normal)");
  set_name("sword");
  set_alias("warlock_weapon");
set_long("These weapons are very unique. These can be seen wielded only by warlocks, "+
"and there are not so many of them left. This weapon is made from some odd "+
"material and it seems to alter it's form. Edges are sharper and harder than "+
"any weapon can possess. Only thing that keeps in form is the handle. It's "+
"made from the darkest silver and grip on it is demonskin. Strange runes can "+
"be seen on edges, and even if the edges change form, the runes keeps on their "+
"places. Nobody knows what those runes say, and warlocks are not willing to "+
"announce those aloud. You can hear faint screaming from this weapon. It is "+
"said that those are the voices of the victims, those who have been slain by "+
"this weapon.\nIt's a chaos sword.\n");
set_max_dur(50);
set_dur(50);
}
set_warlock_boost(int i) {
warlock_boost=10;
call_out("end_warlock_boost", i);
set_short("A Chaos sword (Blessed)");
}
end_warlock_boost() {
warlock_boost=0;
set_short("A Chaos sword (Normal)");
}
query_warlock_weapon() { return 1; }

query_warlock_boost() { return warlock_boost; }

query_wc() { return class_of_weapon+warlock_boost; }

weapon_class() { return class_of_weapon+warlock_boost; }


query_value() { return 0; }

query_no_save() { return 1; }

drop() {
destruct(this_object());
return 1;
}

get() {
destruct(this_object());
return 0;
}