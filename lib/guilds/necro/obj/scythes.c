/* this is a special weapon for undead horde only ~/
/* it has no slot, no descs etc */
int wc, weight;

query_damage(string str) {
  if(str == "slash") return 60;
  if(str == "bash") return 30;
  if(str == "pierce") return 10;
}

query_name() {
  return "scythes";
}
query_type() {
  return "axe";
}
query_wielded() {
  return 1;
}
query_weight() {
  return weight;
}
set_weight(int w) {
  weight = w;
}
set_wc(int i) {
  if(i>80) {
    i = 80;
    write("Scythes cannot be enchanted anymore.\n");
  }
  wc = i;
}
query_wc() {
  return wc;
}
