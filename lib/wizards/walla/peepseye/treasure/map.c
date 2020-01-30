reset(arg) {       
  if(arg) return;
}
init() {
    ::init();
   add_action("map", "map");
}
 
map(arg) {
    if (arg) {
        return 0;
    }
   cat("/wizards/walla/map");
 return 1;                  
}
short() {
  return "the map of treasure hunt";
}
id(str) {
  return str == "map";
}
long() {
  write("this is the map.\n");
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
