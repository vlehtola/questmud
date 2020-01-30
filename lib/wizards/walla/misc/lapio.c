reset(arg) { 
  if(arg) return;
}
short() {
  return "shovel";
}
id(str) {
  return str == "shovel";
}
long() {
  write("this is a shovel goddamit, dig with it.\n");
}
drop() {
  return 0;
}
get() {
return 1;                  
}
query_weight() {
  return 1;
}
