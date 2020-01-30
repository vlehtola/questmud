inherit "obj/armour";

start() {
  set_class(1);
  set_sub_type("plate mail");
  set_short("A chaos armour");
  set_name("armour");
  set_alias("warlock_armour");
set_long("Chaos armour, armour of the Warlocks. These armours have "+
"been along in many battles between warlocks and paladins, but those have not "+
"left any marks on these fine pieces of metal. Mainly the armour is dark and "+
"black, and some strange mist seem to cover it's surface. Speaking of which, "+
"this metal cannot be found from this realm. It's from somewhere beyond void, "+
"if there is such place. Forged by warlocks, they have added power of tortured "+
"souls in these armours, granting them great powers. Armour is decorated by "+
"carvings, symbolizing their gods. Also gems are used to decorate shoulders. "+
"Gems are mostly deep red by color, and shape is like human skull, but only "+
"with horns");
}
set_timer(int i) {
call_out("end_chaos_armour", i);
}
end_chaos_armour() {
write("Your chaos armour dissipates and trembels to ashes.\n");
destruct(this_object());
return 1;
}

query_warlock_armour() { return 1; }

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