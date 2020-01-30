reset(arg) {
  if(arg) return;
}
 
init() {
  add_action("joo", "joo");
}
 
joo() {
  this_player()->death();
  write("Etta semmosta talla kertaa...\n");
}
 
short() {
  return "Alright, this object has a short";
}
 
id(str) {
  return str == "object";
}
 
long() {
  write("turha testi vekotin... You can 'joo' with this item.\n");
}
 
drop() {
  return 1;
}
 
get() {
  return 1;
}
 
query_weight() {
  return 1000;
}
 
