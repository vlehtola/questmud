/* this is a special weapon for undead horde only ~/
/* it has no slot, no descs etc */
int wc, weight;

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
query_shield_factor() {
  return wc/10;
}
set_wc(int i) {
  if(i>100) i = 100;
  wc = i;
}
query_wc() {
  return wc;
}
