EQ_FILTER(string item,object from) {  
  object ob, OBJ, *items, *inv, *already;
  int a, b, e;
  string *comma, eq;

   
inv = all_inventory(from);
comma = explode(item, ",");  
if(sizeof(comma) > 1) {
  items = ({ });
  already = ({ });
  inv = all_inventory(from);
  for(a = 0; a < sizeof(comma); a++) {
if(sscanf(comma[a], "all %s", eq) == 1) {
for(e = 0; e < sizeof(inv); e++) {
  if(inv[e] -> id(eq) && (!(member_array(inv[e], already) != -1))) {
  if(!living(inv[e])) {
    items += ({ inv[e] });
    already += ({ inv[e] });
   }
  }
 }
}

if(OBJ = present(comma[a], from)) {
    if(!(member_array(OBJ, already) != -1) && !living(OBJ)) {
     items += ({ OBJ });
     already += ({ OBJ });
    }
  }
}
if(!sizeof(items)) { return 0; }
  return items;
}

if(sscanf(item, "all %s", item) == 1) {
  inv = all_inventory(from);
  b = sizeof(inv);
  items = ({ });
for(a = 0; a < b; a++) {
  if(inv[a] -> id(item)) {
    if(!living(inv[a])) { 
    items += ({ inv[a] });
  }
 }
}
if(!sizeof(items)) { return 0; }
  return items;
}
  
if(item == "all") { return all_inventory(from); } 
  else if(!(ob = present(item, from))) { return 0; }
 
  if(ob && !living(ob)) items = ({ ob, });  
if(!sizeof(items)) return 0;
else  
return items;
}  
