string name;
reset(arg) {
    if (arg) { return; }
  name = "dummy"; set_living_name(name); enable_commands();
}
id(str) {
    return str == name;
}
query_name() { return name; }
query_max_hp() { return 10000; }
long() {
    write("This is a test dummy. It reports the damage 
done.\n");
}
short() {
    return "A test dummy";
}'
hit_player(dam, dam_type) {
  int d,da;
  if (dam) {
    if (dam_type == 0) { dam_type = 1; }
    d = dam;
    da = dam_type;
    say("Dummy says: 'OUCH! That did " + d + " points of " + 
da + " damage.'\n");
    return d;
  }
}
hit_with_spell(dam, dam_type) {
  int d,da;
  if (dam) {
    if (dam_type == 0) { dam_type = 1; }
    d = dam;
    da = dam_type;
    say("Dummy says: 'OUCH! That did " + d + " points of " + 
da + " damage.'\n");
    return d;
  }
}
query_attack() { return this_player(); }
